// UART functions
#include "function_prototype.h"
#include "sysfunc.h"
#include "uart.h"

// Инициализация режима UART
// speed = 0 - 38400, 1 - 57600, 2 - 115200 - скорость обмена
// databits = 7, 8 - длинна символа
// stopbits = 1, 2 - кол-во передаваемых стоповых бит
// parity = 0 - без контроля четности, 1 - контроль четности, нечетый, 2 - четный
// iface = 0 - USB, 1 - оптика
void UART_init(byte databits, byte stopbits, byte parity, byte iface)
{
  P3SEL |= BIT6 | BIT7;       // выбор функции USART1
  U1CTL = 0;                  // инициализация состояния USART
  ME2 |= UTXE1 + URXE1;       // включить приемник и передатчик USART1

  if (databits == 7) U1CTL &= ~CHAR;        // 7-разрядная длинна символа
  if (databits == 8) U1CTL |= CHAR;         // 8-разрядная длинна символа
  if (stopbits == 1) U1CTL &= ~SPB;         // 1 стоповый бит
  if (stopbits == 2) U1CTL |= SPB;          // 1 стоповых бита
  if (parity == 0) U1CTL &= ~PENA;          // контроль четности отключен
  if (parity == 1) U1CTL = (U1CTL & ~PEV) | PENA; // контроль четности, нечетный
  if (parity == 2) U1CTL |= PENA | PEV;     // контроль четности, четный

  P5DIR |= BIT0;             // переключение мультиплексора на USB/оптику
  if (iface == 0)
    P5OUT |= BIT0;
  if (iface == 1)
    P5OUT &= ~BIT0;    
  U1TCTL |= SSEL1;

  //U1BR = Тактовая частота/требуемая скорость
  //Младший разряд
  U1BR0 = 0x2B;
  //Старший разряд
  U1BR1 = 0x02;
  //Дробная часть
  U1MCTL = 0x37;
}


// отключение режима UART
void UART_off()
{
  P3SEL |= BIT6 | BIT7;       // выбор функции USART1
  ME2 &= ~(UTXE1 + URXE1);    // выключить приемник и передатчик USART1
  U1CTL = SWRST;              // отключение USART1
}


// вывод строки символов (символ с кодом 0 - конец строки)
void UART_message(char * buf)
{
  word i=0;
  while (buf[i])
    UART_sendbyte(buf[i++]);    // передача сивола
}


// передача байта
void UART_sendbyte(char byte)
{
  while (!(IFG2 & UTXIFG1));    // проверка готовности буфера передачи USART1
  U1TXBUF = byte;               // передача байта
}


// получение байта
char UART_getbyte()
{
  while (!(IFG2 & URXIFG1));    // проверка готовности буфера приема USART1
  return U1RXBUF;               // возврат полученного байта
}
