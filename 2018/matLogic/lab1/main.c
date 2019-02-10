#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "r_n.h"
#include "task.h"

int main(){
  char i_arr[100];
  char* result;
  int count;
  result=(char*)malloc(sizeof(char)*100);
  scanf("%s",i_arr);
  count=revers_note(i_arr,result);
  printf("\n%s\n",result);
  printf("task 1\n");
  task_1(result,count);
  printf("\n\ntask 2\n");
  task_2(result,count);
  printf("task 5\n");
  task_5(result,count);


}
