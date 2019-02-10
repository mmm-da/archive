#ifndef LEX_CHECKER_H
#define LEX_CHECKER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#define VAR_NAME_SIZE 50
enum op_types {OP_ERROR=-1,OP_CLR=0,OP_IN=1,OP_OUT=2,OP_MOV=3,OP_SUB=4,OP_ADD=5,OP_DIV=6,OP_MLT=7};

typedef struct Operation{
    char op_type;
    token_var* var_1;
    char var_1_state;//0 - не нужна для операции; 1 - в var записана переменная; 2 - в var записана числовая константа без имени
    token_var* var_2;
    char var_2_state;
}token_op;

token_op* get_operator(char* str);
token_var* get_var(char* str);
char check_var(char* str);
void token_run(token_op* op,table* var_table);
int token_input(FILE *f_in, char *str);

#endif
