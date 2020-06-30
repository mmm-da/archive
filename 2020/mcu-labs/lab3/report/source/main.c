#include <msp430.h> 
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"
#include "keys.h"

#define KEYS_i2c_addr 0x73
/*
 * main.c
 */
char state = 0;
char key_press = 0;
char key = 0;
int delay = 0;

void Custom_Speed_Init_I2C(){
  P3SEL |= 0x0A;           // Выбор альтернативной функции для линий порта P3
                           // в режиме I2C SDA->P3.1, SCL->P3.3
  U0CTL |= I2C + SYNC;     // Выбрать режим I2C для USART0
  U0CTL &= ~I2CEN;         // Выключить модуль I2C
// Конфигурация модуля I2C
  I2CTCTL=I2CSSEL_2;      // SMCLK
  // нужно установить 60000 Гц 
  I2CPSC = 2; //пределитель тактовой частоты 
  I2CSCLH = 21;         // High period of SCL
  I2CSCLL = 21;         // Low period of SCL
  U0CTL |= I2CEN;         // Включить модуль I2C
  // формирование строба сброса I2C-регистров PCA9538 - RST_RG1->P3.1 и RST_RG2->P3.2
  P3DIR |= 0x05;            // переключаем эти ножки порта на вывод,
  P3SEL &= ~0x05;           //   выбираем функцию ввода-вывода для них
  P3OUT &= ~0x05;           //   и формируем строб сброса на 1 мс
  wait_1ms(1);
  P3OUT |= 0x05;
};

void reset_keyboard(){
    I2C_WriteByte(0x03,0x0F,KEYS_i2c_addr);
    I2C_WriteByte(0x01,0x0F,KEYS_i2c_addr);
};

void set_keyboard(){
    I2C_WriteByte(0x03,0x0F,KEYS_i2c_addr);
    I2C_WriteByte(0x01,0xFF,KEYS_i2c_addr);
};

void scan_key(){
    key_press = 0;
    key = KEYS_scannow();
            switch(key){
                case '1':
                    delay-=15;
                    break;
                case '2':
                    delay+=15;
                    break;
                case '0':
                    LED_clear();
                    state = 1;
                    break;
                case '*':
                    LED_clear();
                    state = 0;
                    break;
                case '#':
                    LED_clear();
                    state = 2;
                    break;
            }
            reset_keyboard();
};
void main(void) {
    WDTCTL = WDTPW + WDTHOLD;
    Init_System_Clock();
    P1IE |= BIT7;
    P1IFG &= !BIT7;
    P1IES |= BIT7;
    __enable_interrupt();

    Init_I2C();
    LED_clear();
    reset_keyboard();
    while(1){
        if(key_press){
            scan_key();
        }
        switch(state){
            case 0:
                LED_fx1(delay);
                break;
            case 1:
                LED_fx2(delay);
                break;
            case 2:
                LED_fx3(delay);
                break;
    };
}

#pragma vector=PORT1_VECTOR
__interrupt void keyboard_interrupt(void)
{
    key_press = 1;
    P1IFG &= ~BIT7;
}
