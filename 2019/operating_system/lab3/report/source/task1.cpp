#include "task1.hpp"
#include <QDebug>

Task1::Task1(){
    l1 = new QHBoxLayout;
    l2 = new QHBoxLayout;
    timeout = new QLineEdit(QString::number(timeoutValue));
    process = new QLineEdit(processName);
    counter = new QLabel("0");
    processLabel = new QLabel("Отслеживаемый процесс");
    timeoutLabel = new QLabel("Таймаут");
    button = new QPushButton("Запустить счетчик");
    QVBoxLayout *layout = new QVBoxLayout;
    statusLabel = new QLabel("Запустите таймер.");

    l1->addWidget(timeoutLabel);
    l1->addWidget(timeout);
    l2->addWidget(processLabel);
    l2->addWidget(process);

    layout->addLayout(l2);
    layout->addLayout(l1);
    layout->addWidget(counter);
    layout->addWidget(button);
    layout->addWidget(statusLabel);
    this->setLayout(layout);

    
    getProcIDByName(processName,&processId);
    qDebug() << processId;
    h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | SYNCHRONIZE,false,processId);
    connect(&timer,SIGNAL(timeout()),
            this,SLOT(timerTick()));
    connect(button,SIGNAL(pressed()),
            this,SLOT(buttonClick()));
    connect(timeout,SIGNAL(textChanged(const QString)),
            this,SLOT(timeoutChange(const QString)));
    connect(process,SIGNAL(textChanged(const QString)),
            this,SLOT(processChange(const QString)));
};

void Task1::buttonClick(){
    timerFlag = !timerFlag;
    if(timerFlag){
        button->setText(QString("Остановить счетчик"));
        timer.start(2000);
        statusLabel->setText(QString("Запустите приложение ")+processName);
    }else{
        button->setText(QString("Запустить счетчик"));
        timer.stop();
        statusLabel->setText("Запустите таймер.");
    };
};

void Task1::timerTick(){
    count++;
    counter->setStyleSheet("background-color: rgb(250,250,95)");
    repaint();
    DWORD r_value = WaitForSingleObject(h,timeoutValue);
    counter->setStyleSheet("background-color: rgb(144,250,95)");
    counter->setText(QString::number(count));
    switch (r_value) {
        case WAIT_OBJECT_0:
            statusLabel->setStyleSheet("color: rgb(0, 0, 0)");
            statusLabel->setText(QString("Приложение ")+processName+QString(" закрыто. Счетчик работает дальше."));
            break;
        case WAIT_TIMEOUT:
            statusLabel->setStyleSheet("color: rgb(0, 0, 0)");
            statusLabel->setText(QString("Время ожидание вышло. Счетчик работает дальше."));
            break;
        case WAIT_FAILED:
            counter->setStyleSheet("background-color: rgb(120,0,0)"); 
            statusLabel->setStyleSheet("color: rgb(255, 100, 100)");
            statusLabel->setText("Приложение не найдено или произошла ошибка.");
    }
    CloseHandle(h);
    getProcIDByName(processName,&processId);
    h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | SYNCHRONIZE,false,processId);
};

void Task1::timeoutChange(const QString & text){
    timeoutValue = text.toInt();
};  

void Task1::processChange(const QString & text){
    timer.stop();
    button->setText(QString("Запустить счетчик"));
    timerFlag = false;
    processName = text;
    CloseHandle(h);
    getProcIDByName(processName,&processId);
    qDebug() << processId;
    h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | SYNCHRONIZE,false,processId);
};

bool getProcIDByName(QString pr_name, DWORD *ID){
    DWORD len = 1000, size_needed, ID_arr[len];
    HANDLE h;
    WCHAR w_name[255];
    QString name;
    EnumProcesses(ID_arr, len*sizeof(DWORD), &size_needed);
    for (uint i = 0; i < size_needed/sizeof(DWORD); i++){
        h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, ID_arr[i]);
        if (!GetModuleBaseNameW(h, NULL, w_name, 255)) name = "";
        else name = QString::fromWCharArray(w_name);
        if (name.toLower() == pr_name.toLower()){
            CloseHandle(h);
            if (ID != nullptr) *ID = ID_arr[i];
            return true;
        }
        CloseHandle(h);
    }
    return false;
}
