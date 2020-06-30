#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

const float HIH_zero_offset = 0.958;    // параметр "начальное смещение" датчика влажности, В
const float HIH_slope = 0.03068;        // параметр "угол наклона датчика", В / %RH
const float HIH_ion = 3.3;              // опорное напряжение, В
const float HIH_divisor = 1.1;          // коэффициент резистивного делителя
const float INA_RS = 0.21;              // измерительное сопротивление, Ом
const float INA_RL = 30.1;              // сопротивление нагрузки, Ом

float current_meansurment,humidity_meansurment;
char msg_str[16];

void init_uninterrupted_meansurement(){
    //Пины порта 6 настраиваем на функцию АЦП
    // P6.0 - датчик влажности
    // P6.1 - датчик потребления тока
    P6SEL |= BIT0 + BIT1;
    //Настройка запуска выборки АЦП12 по сигналу OUT0 таймера B
    //Настройка режима последовательности преобразования канала 0,1 АЦП и разрешение прерываний

    //Включить ядро ADC12
    ADC12CTL0 = ADC12ON;
    //Условие запуска выборки OUT0 таймера B, условие запуска преобразования таймер выборки,
    //  начальный адрес преобразования ADC12MEM0, делитель частоты 7, тактирование от ADC12OSC, режим повторяющейся последовательности каналов
    ADC12CTL1 = SHS_1 + SHP + CSTARTADD_0 + ADC12DIV1 + ADC12DIV2 + CONSEQ0 + CONSEQ1;
    //Канал 0 - датчик влажности
    ADC12MCTL0 = SREF_3 + INCH_0;
    //Канал 1 - датчик потребления тока
    ADC12MCTL1 = SREF_3 + INCH_1 + EOS;
    //Прерывания по 0 и 1 каналу разрешены
    ADC12IE = 3;
    //Разрешить преобразование
    ADC12CTL0 |= ENC;

    //Настройка канала 0 таймера B на генерацию сигналов в OUT0 раз в 10 мс
    //Тактирование SMCLK - 32768 гц, делитель - 1, режим вверх
    TBCTL = TBSSEL0 + MC0;
    //Режим вывода 5 - Переключение
    TBCCTL0 = OUTMOD3;
    //Запуск таймера, период таймера - половина рабочего периода 
    TBCCR0 = 164;
};

#pragma vector = ADC12_VECTOR
__interrupt void adc12_interupt(void)
{
    if (ADC12IFG & BIT0 == 1){
        //Расчет показания датчика
        humidity_meansurment = (((ADC12MEM0/4095.0)* HIH_ion * HIH_divisor)-HIH_zero_offset) / HIH_slope;
        //Вывод показаний в 1 строку LCD
        LCD_set_pos(0,0);
        sprintf(msg_str,"Влажность: %5.3f",humidity_meansurment);
        LCD_message(msg_str);
        //Сброс флага прерываний
        ADC12IFG = 0;
    }
    if (ADC12IFG & BIT1 == 1){
        //Расчет показания датчика
        current_meansurment = (ADC12MEM1*3.3) / (4095.0 * INA_RS * INA_RL);
        //Вывод показаний в 2 строку LCD
        LCD_set_pos(1,0);
        sprintf(msg_str,"Потребление: %3.2f",current_meansurment);
        LCD_message(msg_str);
        //Сброс условия старта выборки/преобразования
        TBCCTL0 &= ~OUT;
        //Сброс флага прерываний
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
    LCD_message("показаний.");
    init_uninterrupted_meansurement();
    while(1){

    };
};


