#ifndef RPN_H
#define RPN_H
#include "rpn.h"
#include "utilities.h"
char *to_rpn(char *str, char *varlist);
int calculator(char *eq);
void free_table(char **t, int n, int m);
char **calc_table(char *rpn, char *vars, int *n, int *m);
#endif /* RPN_H */
