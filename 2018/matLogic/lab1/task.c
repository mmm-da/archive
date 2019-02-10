#include "stack.h"
#include "r_n.h"
#include "task.h"
#include <string.h>
#include <stdlib.h>

int expn(int e){
  return 2<<e;
}

void create_calcStr(char* str,char** table, int line,char *r){
  int j=0;
  while (j<strlen(str)){
    if (str[j]>='A' && str[j]<='Z'){
      r[j]=table[line][str[j]-'A']+'0';
    }
    else r[j]=str[j];
    j++;
  }
  r[j]='\0';
}


void fill_table(char **table, int column, int row, int count){
  if (count == 1) return;
  for (int i = 0; i < (count/2); i++){
    table[i+row][column] = 0;
  }
  fill_table (table, column + 1, row, count/2);
  for (int i = (count/2); i < count; i++){
    table[i+row][column] = 1;
  }
  fill_table (table, column + 1, row+count/2, count/2);
}

char** table_Init(int size){
    char** r;
    int m=1<<size-1;
    r=(char**)malloc(sizeof(char*)*m);
    for(int i=0;i<m;i++){
      r[i]=(char*)malloc(sizeof(char)*(size+1));
    }
    return r;
};


char rn_Calc(char* str){
  stack buff;
  stack *buffer=&buff;
  int i=0;
  char t1,t2;
  stack_init(buffer);
  while(str[i]!=0){
    switch(str[i]){
      case SUM:
        t1=stack_pop(buffer);
        t2=stack_pop(buffer);
        stack_push(buffer,t1||t2);
      break;
      case MLT:
        t1=stack_pop(buffer);
        t2=stack_pop(buffer);
        stack_push(buffer,t1&&t2);
      break;
      case INV :
        t1=stack_pop(buffer);
        stack_push(buffer,!t1);
      break;
      default :
        stack_push(buffer,str[i]-'0');
    }
    i++;
  }
  return stack_pop(buffer);
}

void task_2(char* str,int size){
  char** table;
  char t[200];
  char f=1;
  int s=1<<size;
  table=table_Init(size+1);
  fill_table(table,0,0,1<<size);
  for(int i=0;i<(1<<size);i++){
    create_calcStr(str,table,i,t);
    table[i][size+1]=rn_Calc(t);
    if(table[i][size+1]==0){
      f=0;
    }
  }
  if (f==1){
    printf("function is validity\n");
  }
  else{
    printf("function isn't validity\n");
  }
}


void task_5(char* str,int size){
  char** table;
  char t[200];
  int s=1<<size;
  table=table_Init(size+1);
  fill_table(table,0,0,1<<size);
  for(int i=0;i<(1<<size);i++){
    create_calcStr(str,table,i,t);
    table[i][size+1]=rn_Calc(t);
    if(table[i][size+1]==0){
      for(int j=0;j<size;j++){
        printf("%d ",table[i][j]);
      }
      printf("\n");
    }
  }
}

void task_1(char* str,int size){
  char** table;
  char t[200];
  int s=1<<size;
  table=table_Init(size+1);
  fill_table(table,0,0,1<<size);
  for(int i=0;i<(1<<size);i++){
    create_calcStr(str,table,i,t);
    table[i][size]=rn_Calc(t);
  }
  for(int i=0;i<(1<<size);i++){
      for(int j =0;j<=size;j++){
          printf("%d ",table[i][j]);
      }
      printf("\n");
  }
}
