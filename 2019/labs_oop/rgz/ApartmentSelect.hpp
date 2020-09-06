#pragma once
#include <QtWidgets>
#include "SignalButton.hpp"
#include "ApartmentsPanel.hpp"


class ApartmentSelect:public QWidget{
    Q_OBJECT
    int floors;
    int apart_per_floor;
    QList<SignalButton*> apartment_buttons;
    QGridLayout* grid_layout;
    QVBoxLayout* layout; 
    public:
        ApartmentSelect(int floors,int apart):floors(floors),apart_per_floor(apart),QWidget(){
            grid_layout = new QGridLayout();
            QLabel* lbl = new QLabel("Выберите номер квартиры для связи.");
            layout = new QVBoxLayout();
            layout->addWidget(lbl);
            for(int i=0,count=1;i<floors;i++){
                for(int j=0;j<apart_per_floor;j++,count++){
                    apartment_buttons.push_back(new SignalButton(count,QString::number(count)));
                    grid_layout->addWidget(apartment_buttons.last(),i,j);
                    connect(apartment_buttons[count-1],SIGNAL(b_clicked(int)),this,SLOT(show_apart_window(int)));
                }
            };
            layout->addLayout(grid_layout);
            this->setLayout(layout);
        };
    public slots:
        void show_apart_window(int num);
        void apart_open_door(int apart);
        void apart_open_conn(int apart);
        void apart_close_conn(int apart);
    signals:
        void open_door(int apart);
        void open_conn(int apart);
        void close_conn(int apart);
};