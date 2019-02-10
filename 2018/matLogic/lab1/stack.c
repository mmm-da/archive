#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

const int STACK_OVERFLOW=100;
const int STACK_EMPTY=101;

void stack_init(stack *stk) {
  stk->top = 0;
}

void stack_push(stack *stk, BASE_T f) {
  if(stk->top < STACK_SIZE) {
    stk->elem[stk->top] = f;
    stk->top++;
  } else{
    stack_error=STACK_OVERFLOW;
    printf("STACK OVERFLOW");
    exit(STACK_OVERFLOW);}
}

BASE_T stack_pop(stack *stk) {
  BASE_T elem;
  if((stk->top) > 0) {
    stk->top--;
    elem = stk->elem[stk->top];
    return(elem);
   }else {
    stack_error=STACK_EMPTY;
    printf("STACK IS EMPTY");
    exit(STACK_EMPTY);}
}

BASE_T stack_top(stack *stk) {
 char t = stack_pop(stk);
 stack_push(stk,t);
 return(t);}

int stack_empty(stack *stk) {
   if((stk->top) == 0)    return(1);
   else return(0);
 }
