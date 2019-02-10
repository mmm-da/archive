#ifndef STACK
#define STACK

#define STACK_SIZE 100
#define BASE_T char
int stack_error;

extern const int STACK_OVERFLOW,STACK_EMPTY;

typedef struct stk {
  BASE_T elem[STACK_SIZE];
  int top;
}stack;

void stack_init(stack *stk);
void stack_push(stack *stk, BASE_T f);
BASE_T stack_pop(stack *stk);
BASE_T stack_top(stack *stk);
int stack_empty(stack *stk);

#endif
