#include "task3.hpp"

Task3::Task3(){
    QHBoxLayout *layout = new QHBoxLayout;
    processList = new QTableWidget;
    memMap = new QTableWidget;

    th32SnapToQTable(processList);

    connect(processList,SIGNAL(cellDoubleClicked(int,int)),
            this,SLOT(memoryMapBuild(int,int)));
    connect(this,SIGNAL(clearMapTable()),
            memMap,SLOT(clear()));
    layout->addWidget(processList);
    layout->addWidget(memMap);
    this->setLayout(layout);
};

void Task3::memoryMapBuild(int row, int column){
    QString rowProcessName = this->processList->item(row,1)->text();
    emit clearMapTable();
    QMessageBox *msg = new QMessageBox;
    msg->setText(rowProcessName);
    msg->show();
    memoryMapToQTable(memMap,rowProcessName);
};

void th32SnapToQTable(QTableWidget* table){
    // Снимки из ToolHelp32
    table->setRowCount(0);    
    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;
    DWORD dwPriorityClass;

    table->setColumnCount(2);
    table->setHorizontalHeaderLabels({"ID процесса","Название процесса"});
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int i=0;
    // Получаем снимок
    hProcessSnap = CreateToolhelp32Snapshot(
                TH32CS_SNAPPROCESS, // Включить процессы
                0 // текущий процесс
                );
    if( hProcessSnap == INVALID_HANDLE_VALUE ){
        QMessageBox boxError1;
        boxError1.setText("Ошибка получения снимка.");
        boxError1.exec();
    }

    // Устанавливаем размер структуры
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Получаем информацию о первом процессе в списке
    // при неудаче завершаем работу.
    if (!Process32First(hProcessSnap, &pe32)){
        QMessageBox boxError2;
        boxError2.setText("Ошибка получения информации о процессе.");
        boxError2.exec();
        CloseHandle( hProcessSnap );
    }
    // Перебор процессов для определения количества
    do{
        i++;
    }while(Process32Next(hProcessSnap, &pe32));
    table->setRowCount(i);
    Process32First(hProcessSnap, &pe32);
    i=0;
    // Заносим информацию о процессах в таблицу
    do{
        i++;
        // Имя
        QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromWCharArray(pe32.szExeFile));
        table->setItem(i,1,nameItem);

        QTableWidgetItem* idItem;

        // ID
        idItem = new QTableWidgetItem("0x"+QString::number(i,16));
        table->setItem(i,0,idItem);
        table->resizeColumnsToContents();
    } while(Process32Next(hProcessSnap, &pe32));

    // В первую строку допишем текущий процесс
    i = 0;
    // Имя
    QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromWCharArray(pe32.szExeFile));
    table->setItem(i,1,nameItem);

    QTableWidgetItem* idItem;

    // ID
    idItem = new QTableWidgetItem("0x"+QString::number(i,16));
    table->setItem(i,0,idItem);
    CloseHandle(hProcessSnap);
};

void memoryMapToQTable(QTableWidget* table,QString processName){
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels({"Базовый адрес","Базовый адрес выделенной области","Размер региона","Состояние","Защита","Тип"});
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    int i = 0;
    table->setRowCount(1);
    MEMORY_BASIC_INFORMATION mbi;
    SYSTEM_INFO info;
    GetSystemInfo(&info);
    int hMod = 0;
    int pageSize= 4096;
    DWORD lpList = 0;
    HANDLE hProcess = getProcessHandleByName(processName);
    if(hProcess == NULL){
        int last_error=GetLastError();
        QMessageBox *errHandle = new QMessageBox;
        errHandle->setText(QString("Дескриптор не был получен. Error code:")+QString::number(last_error));
        errHandle->show();
    }
    else{
        int flag = 1;
        while (flag) {
                table->setRowCount(i+1);
                flag = VirtualQueryEx(hProcess, (LPCVOID)hMod, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
                hMod = hMod + mbi.RegionSize;
                //QMessageBox *msg = new QMessageBox;
                //msg->setText(QString::number(i)+": "+"0x"+QString::number((DWORD)mbi.BaseAddress,16)+" flag: "+QString::number(flag));
                //msg->show();

                QTableWidgetItem* baseAdress = new QTableWidgetItem("0x"+QString::number((long)mbi.BaseAddress,16));
                QTableWidgetItem* allocationBase = new QTableWidgetItem("0x"+QString::number((long)mbi.AllocationBase,16));
                QTableWidgetItem* regionSize = new QTableWidgetItem(QString::number(mbi.RegionSize/pageSize)+QString("p"));
                QString state;
                switch(mbi.State){
                  case MEM_COMMIT:
                     state = "COMMIT";
                     break;
                  case MEM_FREE:
                     state = "FREE";
                     break;
                  case MEM_RESERVE:
                     state = "RESERVE";
                     break;
                };
                QTableWidgetItem* stateTable = new QTableWidgetItem(state);
                QString type;
                switch(mbi.Type){
                    case MEM_IMAGE:
                        state = "IMAGE";
                        break;
                    case MEM_MAPPED:
                        state = "MAPPED";
                        break;
                    case MEM_PRIVATE:
                        state = "PRIVATE";
                        break;
                };
                QTableWidgetItem* typeTable = new QTableWidgetItem(type);
                QString protect;
                switch(mbi.AllocationProtect){
                    case PAGE_EXECUTE:
                        protect = "EXECUTE";
                        break;
                    case PAGE_EXECUTE_READ:
                        protect = "EXECUTE_READ:";
                        break;
                    case PAGE_EXECUTE_READWRITE:
                        protect = "EXECUTE_READWRITE";
                        break;
                    case PAGE_EXECUTE_WRITECOPY:
                        protect = "EXECUTE_WRITECOPY";
                        break;
                    case PAGE_READONLY:
                        protect = "READONLY";
                        break;
                    case PAGE_READWRITE:
                        protect = "READWRITE";
                        break;
                    case PAGE_WRITECOPY:
                        protect = "WRITECOPY";
                        break;
                }
                QTableWidgetItem* protectTable = new QTableWidgetItem(protect);
                table->setItem(i,0,baseAdress);
                table->setItem(i,1,allocationBase);
                table->setItem(i,2,regionSize);
                table->setItem(i,3,stateTable);
                table->setItem(i,4,protectTable);
                table->setItem(i,5,typeTable);
                table->resizeColumnsToContents();
                i++;
                if(i==30){
                    flag=0;
                }
        }
    }
    CloseHandle(hProcess);
};

HANDLE getProcessHandleByName(QString &pName){
    char fname[255];
    int str_size = 255;
    DWORD* processesId = new DWORD[255];
    DWORD bytes, size = 255 * sizeof(DWORD);
    //id процессов, /кол-во эл типа dword, передаваемых с hepl первого параметра/, кол-во байт
    if (EnumProcesses(processesId, size, &bytes)) {
        uint count = bytes / sizeof(DWORD);

        for (uint i = 0; i < count; i++) {
            HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | SYNCHRONIZE, false, (int) processesId[i]);
            if (GetModuleFileNameExA(h, NULL, fname, size)) {
                QString name = fname;
                name.remove(0, name.lastIndexOf("\\") + 1);
                if (name == pName){
                    QMessageBox *msg = new QMessageBox;
                    msg->setText(QString("Дескриптор найден.")+name+" - "+pName );
                    msg->show();
                    return h;
                }
            }
            CloseHandle(h);
        }
    }
    return NULL;
}
