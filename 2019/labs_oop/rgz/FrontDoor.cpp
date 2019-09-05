#include "FrontDoor.hpp"

void FrontDoorPanel::b_key_slot(){
    int input_key = QInputDialog::
        getInt(this, tr("QInputDialog::getText()"),
        tr("Введите ключ:"), QLineEdit::Password);
    if(input_key == correct_key){
        emit record_open_door(correct_key);
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Неверный ключ.");
        msgBox.exec();
        emit record_wrong_key(input_key);
    }
};
void FrontDoorPanel::b_call_slot(){
    emit b_call_click();
};