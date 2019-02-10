#ifndef MATR_DATA
#define MATR_DATA

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

#endif //MATR_DATA
