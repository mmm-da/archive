#include "mainwindow.hpp"

QColor normalColor;
QColor countColor = QColor("#fbfb46");

MainWindow::MainWindow(){
    layout = new QVBoxLayout;

    status = new QLabel("0");
    normalColor = status->palette().color(status->backgroundRole());

    timerButton = new QPushButton("Создать таймер");
    processButton = new QPushButton("Запустить отсчет");

    layout->addWidget(timerButton);
    layout->addWidget(processButton);
    layout->addWidget(status);
    this->setLayout(layout);
    connect(this->processButton,SIGNAL(pressed()),
            this,SLOT(processBClick()));
    connect(this->timerButton,SIGNAL(pressed()),
            this,SLOT(timerBClick()));
    connect(&runTimer, SIGNAL(timeout()), this, SLOT(runTimerTick()));
    processButton->setEnabled(false);
    
};

void MainWindow::timerBClick(){
    timerState = !timerState;
    if(timerState){
        h = CreateWaitableTimerA(NULL, FALSE, "named_timer");
        if(h != NULL){
            if (GetLastError() == ERROR_ALREADY_EXISTS){
                status->setText("Таймер \"named_timer\" уже создан другим процессом. Дескриптор таймера получен 0х"+ QString::number((long long)h, 16));
            }else{
                status->setText("Таймер \"named_timer\" создан текущим процессом. Дескриптор таймера 0х"+ QString::number((long long)h, 16));
                LARGE_INTEGER l_i;
                //l_i.QuadPart = -1000LL;
                //SetWaitableTimer(h, &l_i, 10000, NULL, NULL, FALSE);
                l_i.QuadPart = 0;
                SetWaitableTimer(h, &l_i, 0, NULL, NULL, FALSE);
            };
            timerButton->setText("Закрыть таймер");
            processButton->setEnabled(true);
        }else{
            status->setText("Ошибка создания таймера");
            timerState = false;
        };
    }else{
        timerButton->setText("Создать таймер");
        processButton->setEnabled(false);
        runTimer.stop();
        CloseHandle(h);
    };
};

void MainWindow::processBClick(){
    runState = !runState;
    if(runState){
        LARGE_INTEGER l_i;
        l_i.QuadPart = -1000LL;
        SetWaitableTimer(h, &l_i, 10000, NULL, NULL, FALSE);
        WaitForSingleObject(h, INFINITE);
        runTimer.start(1000);
        timerButton->setEnabled(false);
        processButton->setText("Остановить отсчет");

    }else{
        runTimer.stop();
        timerButton->setEnabled(true);
        processButton->setText("Запустить отсчет");
    }
};

void MainWindow::runTimerTick(){
    if(!(count % 10)){
        runTimer.stop();
        status->setStyleSheet("background-color: rgb(250,250,95)");
        repaint();
        WaitForSingleObject(h, INFINITE);
        count++;
        status->setStyleSheet("background-color: rgb(144,250,95)");
        status->setText(QString::number(count));
        runTimer.start(1000);
        repaint();
    }else{
        count++;
        status->setText(QString::number(count));
        repaint();
    }
};
