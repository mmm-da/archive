#ifndef TASK_H_
#define TASK_H_
#include <stdlib.h>
#include <stdio.h>
#include "rpn.h"
#include "utilities.h"
#include <math.h>
char* read_permise(unsigned count_of_permise);
void print_consequences(char* str);
char* table_to_pknf_str(char **table,unsigned n,unsigned m);
char* table_to_pdnf_str(char **table,unsigned n,unsigned m);
char** table_to_pknf_arr(char **table,unsigned n,unsigned m,unsigned *count);
#endif
