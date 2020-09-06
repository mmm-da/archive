#include "ApartmentsPanel.hpp"

void ApartmentWindow::door_button_click(){
    emit door_open(this->apart_num);
    close();
};
void ApartmentWindow::connect_button_click(){
    emit connect_open(this->apart_num);
    this->b_connect->setEnabled(false); 
    this->b_open->setEnabled(true); 
    this->b_close->setEnabled(true); 
};
void ApartmentWindow::close_button_click(){
    emit connect_block(this->apart_num);
    close();
};