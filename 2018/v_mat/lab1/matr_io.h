#ifndef MATR_IO
#define MATR_IO
#include "matr_data.h"

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

#endif //MATR_IO
