#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

const float HIH_zero_offset = 0.958;
const float HIH_slope = 0.03068;
const float HIH_ion = 3.3;
const float HIH_divisor = 1.1;
const float INA_RS = 0.21;
const float INA_RL = 30.1;

float current_meansurment,humidity_meansurment;
char msg_str[16];

void init_uninterrupted_meansurement(){
    P6SEL |= BIT0 + BIT1;
    ADC12CTL0 = ADC12ON;
    ADC12CTL1 = SHS_1 + SHP + CSTARTADD_0 + ADC12DIV1 + ADC12DIV2 + CONSEQ0 + CONSEQ1;
    ADC12MCTL0 = SREF_3 + INCH_0;
    ADC12MCTL1 = SREF_3 + INCH_1 + EOS;
    ADC12IE = 2;
    ADC12CTL0 |= ENC;

    TBCTL = TBSSEL0 + MC0;
    TBCCTL0 = OUTMOD_2;
    TBCCR0 = 164;
};

#pragma vector = ADC12_VECTOR
__interrupt void adc12_interupt(void)
{
    if (ADC12IFG & BIT1 == 1){
        humidity_meansurment = (((ADC12MEM0/4095.0)* HIH_ion * HIH_divisor)-HIH_zero_offset) / HIH_slope;
        current_meansurment = (ADC12MEM1*3.3) / (4095.0 * INA_RS * INA_RL);
        LCD_set_pos(0,0);
        sprintf(msg_str,"Влажность: %5.3f",humidity_meansurment);
        LCD_message(msg_str);
        LCD_set_pos(1,0);
        sprintf(msg_str,"Ток: %3.2f",current_meansurment);
        LCD_message(msg_str);
        ADC12IFG = 0;
    }
}



void main(void) {
    WDTCTL = WDTPW + WDTHOLD;
    __enable_interrupt();
    Init_System_Clock();
    Init_System();
    LCD_init();
    LCD_message("Ожидание");
    LCD_set_pos(1,0);
    LCD_message("преобр...");
    init_uninterrupted_meansurement();
    while(1){

    };
};


