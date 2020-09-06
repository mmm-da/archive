#include <QtWidgets>
#include <windows.h>
#include <tchar.h>
#include <psapi.h>
#pragma once



class MainWindow : public QWidget{
    Q_OBJECT
    private:
        HANDLE h;
        int count = 1;
        bool timerState = false;
        bool runState = false;
        QTimer runTimer;
        QVBoxLayout *layout;
        QLabel *status;
        QPushButton *timerButton,*processButton;
    public:
        MainWindow();
    public slots:
        void timerBClick();
        void processBClick();
        void runTimerTick();
};

