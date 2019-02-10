#include <stdio.h>
#include <stdlib.h>

//базовый тип матрицы
typedef int base;

//size - порядок матрицы, val - массив, хранящий коэффициенты
typedef struct _matr{
  unsigned char size;
  base** val;
}matr;

//Столбец свободных членов
typedef struct _col{
  unsigned char size;
  base* val;
}col;

/*
Функция выделяет память для хранения матрицы размера sizexsize и возвращает
указатель на созданную матрицу
*/
matr cr_matrix(unsigned char size);

/*
Функция выделяет память для хранения столбца из size строк
*/
col* cr_columns(unsigned char size, unsigned char m);

/*
Функция освобождает память, занимаемую матрицей a и присваивает указателю
значение NULL
*/
void free_matrix(matr a);

/*
Функция освобождает память, занимаемую столбцом a и присваивает указателю
значение NULL
*/
void free_columns(col* a, unsigned char m);

/*
Процедура предназначена для ввода матрицы коэффициентов a и
m столбцов свободных членов в массив столбцов b
*/
void read_matr(matr a, int m, col* b);

/*
Процедура предназначена для вывода левой части a и
m столбцов свободных членов в массив b
*/
void print_matr(matr a, int m, col* b);

/*
Умножает квадратную матрицу a на число num
*/
void multbynum_matr(matr a, base num);






int main()
{
  matr a;
  col* b;
  int n, m;
  printf("Enter N, M: \n");
  scanf("%i %i", &n, &m);
  a = cr_matrix(n);
  b = cr_columns(n, m);
  printf("Enter %ix%i and %ix%i matrices: \n", n, n, n, m);
  read_matr(a, m, b);
  multbynum_matr(a, 3);
  print_matr(a, m, b);
  free_matrix(a);
  free_columns(b, m);
  return 0;
}








//MATR_DATA

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

//MATR_IO

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

//MATR_MATH

/*
Умножает квадратную матрицу a на число num
*/
void multbynum_matr(matr a, base num)
{
  for (int i=0; i<a.size; i++){
    for (int j=0; j<a.size; j++){
      a.val[i][j]*=num;
    }
  }
}
