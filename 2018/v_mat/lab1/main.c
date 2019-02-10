#include "matr_data.h"
#include "matr_io.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  matr* a;
  col* b;
  int n, m;
  printf("Enter N, M: ");
  scanf("%i %i", n, m);
  a = cr_matrix(n);
  printf("mem");
  b = cr_column(n);
  read_matr(*a, m, b);
  print_matr(*a, m, b);
  return 0;
}
