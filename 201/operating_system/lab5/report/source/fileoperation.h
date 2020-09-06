#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <QString>

#include <windows.h>

class FileOperation
{
public:
    FileOperation();
    QByteArray read(QString path);
    bool write(QByteArray, QString path, bool append = false);
    bool exists(QString path);
    QString currentDir();
private:
    DWORD aligned(DWORD);
    DWORD fileSize(HANDLE);
    ULONGLONG freeSpace(QString);
    DWORD bytes_per_sector;

};

#endif // FILEOPERATION_H
