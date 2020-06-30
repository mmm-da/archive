#include <msp430.h> 
#include "stdio.h"
#include "stdlib.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"
/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW + WDTHOLD;
    Init_System_Clock();
    Init_System();
    __enable_interrupt();
    LCD_init();
    char num[12];
    unsigned int res,last_res;
    while(1){
        res = R22_get_resistance();
        if(res!=last_res){
            LCD_clear();
            LCD_message("R22: ");
            ltoa((long)res,num);
            LCD_message(num);
            last_res = res;
        }
        wait_1ms(100);
    };
}
