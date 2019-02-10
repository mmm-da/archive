#include "r_n.h"
#include <string.h>

char strsearch(char* str,char c){
  int i=0;
  int size=strlen(str);
  while((str[i]!=c)&(i<size)) i++;
  return (i<size);
}

int revers_note(char* str,char* result){
  char arr[30];
  stack buff;
  char t,f1;
  stack *buffer=&buff;
  stack_init(buffer);
  int i=0,j=0,k=0;
  while(str[i]!=0){
    switch(str[i]){
    case SUM :
        if(stack_top(buffer)==MLT) {
          result[j]=stack_pop(buffer);
          j++;
          stack_push(buffer,SUM);}
        else {
        stack_push(buffer,SUM);}
    break;
    case MLT :
      stack_push(buffer,MLT);
    break;
    case INV :
      stack_push(buffer,INV);
      f1=1;
    break;
    case OBR :
      stack_push(buffer,OBR);
    break;
    case CBR :
      while((t=stack_pop(buffer))!=OBR){
        if(t!=OBR){
        result[j]=t;
        j++;}}
    break;
    default:
      if (!(strsearch(arr,str[i]))){
        arr[k]=str[i];
        k++;
      };
      result[j]=str[i];
      j++;
      if(stack_top(buffer)==INV){
        result[j]=stack_pop(buffer);
        j++;
        f1=0;}
    }
    i++;
  }
    while(!(stack_empty(buffer))){
      result[j]=stack_pop(buffer);
      j++;
    };
    result[j]='\0';
    return k;
  }
