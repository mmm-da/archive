#ifndef FILE_H_
#define  FILE_H_
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
unsigned read_point_file(FILE* file_in, point* arr_out);
void write_line_file(point* arr_in,unsigned size);
#endif
