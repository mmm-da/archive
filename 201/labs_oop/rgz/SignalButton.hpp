#pragma once
#include <QtWidgets>

class SignalButton: public QPushButton{
    Q_OBJECT
    int sign;
    signals:
        void b_clicked(int sign);
    private slots:
        void button_click();
    public:
        SignalButton(int sign,QString str):QPushButton(str),sign(sign){
            connect(this,SIGNAL(clicked()),this,SLOT(button_click()));
        };
};