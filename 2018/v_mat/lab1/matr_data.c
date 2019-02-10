#include <stdio.h>
#include <stdlib.h>
#include "matr_data.h"

/*
Функция выделяет память для хранения матрицы размера sizexsize и возвращает
указатель на созданную матрицу
*/
matr cr_matrix(unsigned char size)
{
  //matr* a = (matr*)malloc(sizeof(matr));
  matr a;
  a.size = size;
  a.val = (base**)malloc(sizeof(base*)*size);
  for (int i = 0; i<size; i++){
    a.val[i] = (base*)malloc(sizeof(base)*size);
  }
  return a;
}

/*
Функция выделяет память для хранения m столбцов по size строк
*/
col* cr_columns(unsigned char size, unsigned char m)
{
  col* a = (col*)malloc(sizeof(col)*m);
  for (int i = 0; i<m; i++){
    a[i].size = size;
    a[i].val = (base*)malloc(sizeof(base)*size);
  }
  return a;
}

/*
Функция освобождает память, занимаемую матрицей a и присваивает указателю
значение NULL
*/
void free_matrix(matr a)
{
  for (int i = 0; i<a.size; i++){
    free(a.val[i]);
  };
  free(a.val);
}

/*
Функция освобождает память, занимаемую столбцом a и присваивает указателю
значение NULL
*/
void free_columns(col* a, unsigned char m)
{
  for (int i = 0; i<m; i++){
    free(a[i].val);
  }
  free(a);
  a = NULL;
}
