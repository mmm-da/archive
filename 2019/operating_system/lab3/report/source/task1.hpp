#include <QtWidgets>
#include <windows.h>
#include <tchar.h>
#include <psapi.h>
#pragma once

bool getProcIDByName(QString pr_name, DWORD *ID);

class Task1 : public QWidget{
    Q_OBJECT
    private:
        int count = 0;
        int timeoutValue = 100;
        QString processName = QString("cmd.exe");
        HANDLE h;
        DWORD processId;
        bool timerFlag = false;
        QTimer timer;
        QHBoxLayout *l1;
        QHBoxLayout *l2;
        QLineEdit *timeout;
        QLineEdit *process;
        QLabel *counter;
        QLabel *processLabel;
        QLabel *timeoutLabel;
        QLabel *statusLabel;
        QPushButton *button;
        QVBoxLayout *layout;
    public:
        Task1();
    public slots:
        void buttonClick();
        void timerTick();
        void timeoutChange(const QString & text);        
        void processChange(const QString & text);        
};

