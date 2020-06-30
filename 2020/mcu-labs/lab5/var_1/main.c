#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

char msg_str[16];

void print_meansurments(){
    float hum = HIH_get_hum();
    float cur = INA_get_curr();
    LCD_set_pos(0, 0);
    sprintf(msg_str,"Влажность: %5.3f",hum);
    LCD_message(msg_str);
    sprintf(msg_str,"Потребление: %3.2f",cur);
    LCD_message(msg_str);
};

void main(void) {
    WDTCTL = WDTPW + WDTHOLD;
    __enable_interrupt();
    Init_System_Clock();
    Init_System();
    LCD_init();
    LCD_message("Первое измерение ...");
    print_meansurments();
    //настройка таймера
    TACTL = TASSEL0 + MC0;
    TACCTL0 = CCIE;
    TACCR0 = 33;
    while(1){
    };
};



// обработчик прерываний от таймера
#pragma vector=TIMERA0_VECTOR
__interrupt void timerA_interupt(void)
{
    print_meansurments();
    TACCTL0 &= ~CCIFG;
}
