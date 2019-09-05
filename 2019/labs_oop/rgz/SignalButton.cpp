#include "SignalButton.hpp"

void SignalButton::button_click(){
    emit b_clicked(this->sign);
};