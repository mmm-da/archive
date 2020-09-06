#include "ApartmentSelect.hpp"

void ApartmentSelect::show_apart_window(int num){
    ApartmentWindow* window = new ApartmentWindow(num);
    connect(window,SIGNAL(door_open(int)),this,SLOT(apart_open_door(int)));
    connect(window,SIGNAL(connect_open(int)),this,SLOT(apart_open_conn(int)));
    connect(window,SIGNAL(connect_block(int)),this,SLOT(apart_close_conn(int)));
    window->show();
};

void ApartmentSelect::apart_open_door(int apart){
    emit open_door(apart);
};
void ApartmentSelect::apart_open_conn(int apart){
    emit open_conn(apart);
};
void ApartmentSelect::apart_close_conn(int apart){
    emit close_conn(apart);
};