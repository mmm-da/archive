#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
const char stack_ok = 1;
const char stack_underflow = 2;
const char stack_overflow = 3;
const char stack_mem_error = 4;
stack* stack_init(unsigned size){
    stack* temp_pointer;
    temp_pointer=(stack*)malloc(sizeof(stack));
    if(temp_pointer==NULL){
        stack_error=stack_mem_error;
        exit(stack_error);
    }
    temp_pointer->stack_size=size;
    temp_pointer->stack_arr=(base_type*)malloc(sizeof(base_type)*size);
    temp_pointer->stack_top=-1;
    stack_error=stack_ok;
    temp_pointer->stack_lenght=0;
    return temp_pointer;
}
void stack_put(stack *s, base_type e){
    if(stack_full(s)){
        stack_error=stack_overflow;
        exit(stack_error);
    }
    s->stack_top++;
    s->stack_arr[s->stack_top]=e;
}
base_type stack_get(stack *s){
    if(stack_empty(s)){
        stack_error=stack_underflow;
        exit(stack_error);
    }
    base_type temp;
    temp=s->stack_arr[s->stack_top];
    s->stack_top--;
    return temp;
}
base_type stack_read(stack *s){
    if(stack_empty(s)){
        stack_error=stack_underflow;
        exit(stack_error);
    }
    return s->stack_arr[s->stack_top];
}
  void stack_print(stack *s){
      if(s->stack_top!=0){
      for(int i=0;i<s->stack_top;i++){
          task_out(s->stack_arr[i]);
          printf(", ");
      }
      }
      else{
          printf("empty");
      }
      printf("\n");
  }
int stack_full(stack *s){
    if(s->stack_top>=s->stack_size-1) return 1;
    else return 0;
}
int stack_empty(stack *s){
    if(s->stack_top==-1) return 1;
    else return 0;
}
void stack_done(stack *s){
    free(s->stack_arr);
    free(s);
}
