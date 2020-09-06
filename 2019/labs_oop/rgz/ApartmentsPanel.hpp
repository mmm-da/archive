#pragma once
#include <QtWidgets>

class ApartmentWindow: public QWidget{
    Q_OBJECT
    private:
        int apart_num;
        QPushButton *b_open,*b_connect,*b_close;
        QHBoxLayout* h_layout;
        QVBoxLayout* layout;
    public:
        ApartmentWindow(int num):QWidget(),apart_num(num){
            this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
            this->setWindowTitle(QStringLiteral("Квартира %1").arg(apart_num));
            QLabel* lbl = new QLabel(QStringLiteral("Панель квартиры номер %1").arg(apart_num));
            lbl->setAlignment(Qt::AlignCenter);
            h_layout = new QHBoxLayout();
            layout = new QVBoxLayout();
            b_open = new QPushButton("Открыть");
            b_open->setEnabled(false);
            b_close = new QPushButton("Блокировка");
            b_close->setEnabled(false);
            b_connect = new QPushButton("Связь");
            connect(this->b_open,SIGNAL(clicked()),this,SLOT(door_button_click()));
            connect(this->b_connect,SIGNAL(clicked()),this,SLOT(connect_button_click()));
            connect(this->b_close,SIGNAL(clicked()),this,SLOT(close_button_click()));
            h_layout->addWidget(b_connect);
            h_layout->addWidget(b_open);
            h_layout->addWidget(b_close);
            layout->addWidget(lbl);
            layout->addLayout(h_layout);
            this->setLayout(layout);
        };
    signals:
        void door_open(int apart_num);
        void connect_open(int apart_num);
        void connect_block(int apart_num);
    private slots:
        void door_button_click();
        void connect_button_click();
        void close_button_click();
};

