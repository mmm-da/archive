#ifndef UTILITIES_H
#define UTILITIES_H
#include <stdlib.h>
#include <stdio.h>
int get_len(char *str);
int in_str(char c, char *str);
void sort(char *str);
void print_table(char **table, int rows, int cols);
char *copy(char *s, int len);
#endif /* UTILITIES_H */
