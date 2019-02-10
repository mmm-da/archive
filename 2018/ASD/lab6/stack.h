#ifndef STACK_H_
#define STACK_H_
#include "list.h"

    extern const char stack_ok;
    extern const char stack_underflow;
    extern const char stack_overflow;
    extern const char stack_mem_error;
    char stack_error; // Переменная ошибок

    typedef struct{
        int stack_top;
        unsigned stack_lenght;
        unsigned stack_size;
        base_type* stack_arr;
    } stack;
    stack* stack_init(unsigned size); //Инициализация  стека
    void stack_done(stack *s); //Деструктор
    void stack_put(stack *s,base_type e); //Поместить элемент в стек
    base_type stack_get(stack *s); //Извлечь элемент из стека
    base_type stack_read(stack *s); //чтение без извлечения
    void stack_print(stack *s);
  // Предикаты
    int  stack_empty(stack* s);
    int  stack_full(stack* s);
#endif
