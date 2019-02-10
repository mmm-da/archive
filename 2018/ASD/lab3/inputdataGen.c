#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inputdataGen.h"
int* init_arr(int size){
  int* p;
  p=(int*)malloc(sizeof(int)*size);
  return p;
}

void write_arr(int* arr,int size){
  for(int i=0;i<size;i++){
    printf("%i ",arr[i]);}
  printf("\n");
}

int* sorted_arrGen(int size){
  int* result_arr;
  result_arr=init_arr(size);
  for(int i=0;i<size;i++){
    result_arr[i]=i;
  }
  return result_arr;
}

int* sorted_RarrGen(int size){
  int* result_arr;
  result_arr=init_arr(size);
  for(int i=0;i<size;i++){
    result_arr[i]=size-i;
  }
  return result_arr;
}

int* random_arrGen(int size){
  int* result_arr;
  result_arr=init_arr(size);
  srand(time(NULL));
  for(int i=0;i<size;i++){
    result_arr[i]=rand()%1000;
  }
  return result_arr;
}
