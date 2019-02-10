#include "matr_io.h"
#include <stdio.h>

/*
Процедура предназначена для ввода матрицы коэффициентов a и
m столбцов свободных членов в массив столбцов b
*/
void read_matr(matr a, int m, col* b)
{
  for (int i = 0; i<a.size; i++){
    for (int j = 0; j<a.size; j++){
      scanf("%i", &(a.val[i][j]));
    }
  }
  for (int k=0; k<m; k++){
    for (int i = 0; i<b[k].size; i++){
      scanf("%i", &(b[k].val[i]));
    }
  }
}

/*
Процедура предназначена для вывода левой части a и
m столбцов свободных членов в массив b
*/
void print_matr(matr a, int m, col* b)
{
  for (int i = 0; i<a.size; i++){
    for (int j = 0; j<a.size-1; j++){
      printf("%i*X%i + ", a.val[i][j], j+1);
    }
    printf("%i*X%i = ", a.val[i][a.size-1], a.size);
    for (int k = 0; k<m-1; k++){
      printf("%i; ", b[k].val[i]);
    }
    printf("%i\n", b[m-1].val[i]);
  }
}
