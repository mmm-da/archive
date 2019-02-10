#include <stdio.h>
#include <stdlib.h>
#include "lex_checker.h"

int main(){
    FILE *f_in;
    char src_name[50]="c";
    char token_str[50];
    table* var_table;
    var_table=table_init(VAR_COUNT);
    printf("Input file path:");
    scanf("%s",&src_name);
    f_in=fopen(src_name,"rw+");
    if (f_in == NULL){
        return 1;
    }
    while(token_input(f_in,token_str)){
        token_run(get_operator(token_str),var_table);
    }
    table_done(var_table);
    return 0;
}
