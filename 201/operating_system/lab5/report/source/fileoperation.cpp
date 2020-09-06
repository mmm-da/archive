#include "fileoperation.h"

#include <windows.h>
#include <QDebug>
#include <QDir>

FileOperation::FileOperation(){
    // Необходимо получить размер сектора для выравнивания
    GetDiskFreeSpace(NULL, NULL, &bytes_per_sector, NULL, NULL);
}

QByteArray FileOperation::read(QString path){
    TCHAR *buffer = new TCHAR[MAX_PATH];
    FillMemory(buffer, MAX_PATH, 0);
    // Преобразовали путь к WCHAR
    int len = path.toWCharArray(buffer);
    buffer[len] = '\0';

    // Открытие файла
    HANDLE file_h = CreateFileW(
                buffer,             // Имя
                GENERIC_READ,       // На чтение
                FILE_SHARE_READ,    // Может быть открыт в другой программе
                NULL,               // Флаги безопасности не установлены, наследование не нужно
                OPEN_EXISTING,      // Открывать только существующие
                FILE_FLAG_OVERLAPPED,  // Асинхронные операции
                NULL                    // Шаблона нет
                );

    if (file_h == INVALID_HANDLE_VALUE){
        qDebug() << GetLastError();
        throw std::runtime_error("Не удалось открыть файл");
    }

    // Подготовка буфера и overlapped
    // Помимо размера файла надо оставить место для 0-символа
    DWORD size_in_bytes = aligned(
                fileSize(file_h)  + sizeof (BYTE)
                );
    BYTE *big_buffer = new BYTE[size_in_bytes];

    FillMemory(big_buffer, size_in_bytes, 0);

    // Создание события для асинхронных операций
    HANDLE event = CreateEvent(
                NULL,
                FALSE,
                FALSE,
                NULL
                );
    // Структура OVERLAPPED для асинхронных операций
    OVERLAPPED ovl;
    ovl.hEvent = event;
    ovl.Offset = 0;
    ovl.OffsetHigh = 0;

    // Чтение файла
    BOOL bResult = ReadFile(
                file_h,     // Хендл
                big_buffer, // Буфер
                size_in_bytes, // Размер в байтах
                NULL,       // Количество считанных должно быть NULL при асинхр. оп.
                &ovl        // Структура OVERLAPPED
                );
    DWORD err;
    if (!bResult && (err = GetLastError()) != ERROR_IO_PENDING){
        qDebug() << err;
        CloseHandle(file_h);
        CloseHandle(event);
        delete[] big_buffer;
        throw std::runtime_error("Не удалось прочесть файл");
    }

    // Ожидаем завершения операции чтения
    WaitForSingleObject(event, INFINITE);

    // Получим количество считанных байт
    DWORD actually_read;
    GetOverlappedResult(
                file_h, // Файл
                &ovl,   // Структура OVERLAPPED
                &actually_read, // Сколько прочитали
                TRUE    // Ожидать завершения операции
                );

    // Установим терминатор после всех прочитанных
    big_buffer[actually_read / sizeof(BYTE)] = '\0';

    // Кодировка файла Utf-8
    QByteArray result;
    result.append((char *)big_buffer);
    // Закрытие и очистка
    CloseHandle(file_h);
    CloseHandle(event);
    delete[] big_buffer;

    return result;
}

bool FileOperation::write(QByteArray arr, QString path, bool append){
    // Преобразовываем кодировку текста к UTF-8
    BYTE *big_buffer = (BYTE *) arr.data();
    qDebug() <<"запись в файл" <<arr;
    ULONGLONG buffer_size = arr.size();

    ULONGLONG free_space;
    // Проверяем наличие свободного места
    try {
        free_space = freeSpace(path);
    } catch (std::runtime_error e) {
        throw e;
    }
    if (free_space < buffer_size){
        throw std::runtime_error("Недостаточно места на диске");
    }
    TCHAR *buffer = new TCHAR[MAX_PATH];
    FillMemory(buffer, MAX_PATH, 0);
    // Преобразовали путь к WCHAR
    int len = path.toWCharArray(buffer);
    buffer[len] = '\0';

    HANDLE file_h;
    ULONGLONG current_size = 0;

    // Открытие файла
    if (append){
        file_h = CreateFileW(
                    buffer,             // Имя
                    FILE_APPEND_DATA,       // На дозапись
                    0,                  // не разделять
                    NULL,               // Флаги безопасности не установлены, наследование не нужно
                    OPEN_ALWAYS,      // открывать если существует, создавать если нет
                    FILE_FLAG_OVERLAPPED,  // Асинхронные операции
                    NULL                    // Шаблона нет
                    );
         current_size = fileSize(file_h);
    }else{
        file_h = CreateFileW(
                    buffer,             // Имя
                    GENERIC_WRITE,       // На запись
                    0,                  // не разделять
                    NULL,               // Флаги безопасности не установлены, наследование не нужно
                    CREATE_ALWAYS,      // Только создавать новый
                    FILE_FLAG_OVERLAPPED,  // Асинхронные операции
                    NULL                    // Шаблона нет
                    );
    }

    if (file_h == INVALID_HANDLE_VALUE){
        qDebug() << GetLastError();
        throw std::runtime_error("Не удалось создать файл");
    }

    DWORD size_in_bytes = aligned(
                buffer_size
                );

    // Создание события для асинхронных операций
    HANDLE event = CreateEvent(
                NULL,
                FALSE,
                FALSE,
                NULL
                );
    // Структура OVERLAPPED для асинхронных операций
    OVERLAPPED ovl;
    ovl.hEvent = event;
    ovl.Offset = 0;
    ovl.OffsetHigh = 0;

    // Запись файла
    BOOL bResult = WriteFile(
                file_h,     // Хендл
                big_buffer, // Буфер
                size_in_bytes, // Размер в байтах
                NULL,
                &ovl        // Структура OVERLAPPED
                );
    DWORD err;
    if (!bResult && (err = GetLastError()) != ERROR_IO_PENDING){
        qDebug() << err;
        CloseHandle(file_h);
        CloseHandle(event);
        delete[] big_buffer;
        throw std::runtime_error("Не удалось записать файл");
    }

    // Ожидаем завершения операции записи
    WaitForSingleObject(event, INFINITE);

    // Урезаем файл по реально хранимым данным
    LONG bytes_to_cut = buffer_size + current_size;
    SetFilePointer(file_h, bytes_to_cut, 0, FILE_BEGIN);
    SetEndOfFile(file_h);
    qDebug() << "Сделано";;
    // Закрытие и очистка
    CloseHandle(file_h);
    CloseHandle(event);
    delete[] big_buffer;

    return true;
}

bool FileOperation::exists(QString path){
    TCHAR *buffer = new TCHAR[MAX_PATH];
    FillMemory(buffer, MAX_PATH, 0);
    path.toWCharArray(buffer);
    bool exists = GetFileAttributes(buffer) != DWORD(-1);
    delete[] buffer;
    return exists;
}

QString FileOperation::currentDir(){
    TCHAR *buffer = new TCHAR[MAX_PATH];
    FillMemory(buffer, MAX_PATH, 0);

    GetCurrentDirectoryW(MAX_PATH, buffer);
    QString path = QString::fromWCharArray(buffer);

    delete[] buffer;
    return path;
}

DWORD FileOperation::aligned(DWORD size){
    // Получает ближайшее большее или равное, кратное размеру сектора
    return ((bytes_per_sector + ((size + bytes_per_sector)-1)) & ~(bytes_per_sector -1));
}

// Возвращает размер файла в байтах
DWORD FileOperation::fileSize(HANDLE hFile){
    LARGE_INTEGER file_size;
    GetFileSizeEx(hFile, &file_size);
    DWORD filesize = file_size.LowPart;
    return filesize;
}

ULONGLONG FileOperation::freeSpace(QString path){
    QString win_path = QDir::toNativeSeparators(path);
    int first_delim = win_path.indexOf(QDir::separator());
    int last_delim = win_path.lastIndexOf(QDir::separator());
    // Удаляю букву диска
    win_path.remove(0, first_delim);
    // Удаляю файл
    win_path.chop(win_path.length() - last_delim + 2);
    TCHAR *buffer = new TCHAR[MAX_PATH];
    FillMemory(buffer, MAX_PATH, 0);
    win_path.toWCharArray(buffer);
    ULARGE_INTEGER free_size;

    bool result = GetDiskFreeSpaceEx(
                buffer,         // Путь
                &free_size,     // Кол-во байт доступных пользователю
                NULL,
                NULL
                );
    if (!result){
        throw std::runtime_error("Не удалось получить свободное место");
    }
    ULONGLONG byte_size = free_size.QuadPart;
    delete[] buffer;
    return byte_size;
}
