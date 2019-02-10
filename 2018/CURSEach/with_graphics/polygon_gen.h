#ifndef POINT_GEN_H_
#define POINT_GEN_H_
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include <float.h>
#include "file.h"

extern int count;
void copy_poly(point* dest, point* origin,unsigned size);
int gen_transposition(unsigned* index_arr,unsigned size);
char poly_check_intersect(Line* arr,unsigned size);
void gen_poly(int* index_arr,point* point_arr,Line* poly,unsigned size);
void swap(int *a, int i, int j);
void Line_arr_copy(Line* orig,Line* dest,unsigned size);
Line* min_perimetr_poly(point* arr,unsigned size);
unsigned* gen_index_arr(unsigned size);
double perimetr_poly(Line* arr,unsigned size);
void gen_minimal_poly(point* arr,unsigned size);
#endif
