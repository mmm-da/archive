#include <stdlib.h>
#include "rpn.h"
#include "stack.h"
#include "utilities.h"
char not(char a){
    a = !(a-'0');
    return a+'0';
}
char and(char a, char b){
    char tmp = (a-'0') && (b-'0');
    return tmp+'0';
}
char or(char a, char b){
    char tmp = (a-'0') || (b-'0');
    return tmp+'0';
}
char xor(char a, char b){
    char t_a = a-'0';
    char t_b = b-'0';
    char tmp = (!t_a && t_b) || (t_a && !t_b);
    return tmp+'0';
}
int priority(char c){
    if ('a' <= c && c<='z')
        return -2;
    if (c == '0' || c == '1')
        return -1;
    switch (c){
    case '(':
        return 1;
    case '+':
        return 2;
    case '*':
        return 3;
    case '!':
        return 4;
    case ')':
        return 5;
    default:
        return 0;
    }
}
char *to_rpn(char *str, char *varlist){
    stack s;
    initstack(&s);
    int flag;
    char tmp;
    int tmpprior;
    int varcount = 0;
    varlist[0] = '\0';
    int size = 0;
    int len = get_len(str);
    char *result = (char *)malloc(sizeof(char)*(len+1));
    for (int i = 0; i<len; i++){
        switch (priority(str[i])){
            case -2:
                if (in_str(str[i], varlist)==-1){
                    varlist[varcount++] = str[i];
                    varlist[varcount] = '\0';
                }
            case -1:
                result[size++] = str[i];
                break;
            case 1:
                putstack(&s, str[i]);
                break;
            case 2:
            case 3:
                tmpprior = priority(str[i]);
                flag = emptystack(&s);
                while (!flag){
                    getstack(&s, &tmp);
                    if (priority(tmp) >= tmpprior){
                        result[size++] = tmp;
                    }else{
                        putstack(&s, tmp);
                        flag = 1;
                    }
                    flag = flag || emptystack(&s);
                }
                putstack(&s, str[i]);
                break;
            case 4:
                putstack(&s, str[i]);
                break;
            case 5:
                getstack(&s, &tmp);
                while (priority(tmp) != 1){
                    result[size++] = tmp;
                    getstack(&s, &tmp);
                }
                break;
        }
    }
    while (!emptystack(&s)){
        getstack(&s, &tmp);
        result[size++] = tmp;
    }
    result[size++] = '\0';
    result = (char *)realloc(result, size*sizeof(char));
    freestack(&s);
    return result;
}

int calculator(char *eq){
    int i = 0;
    char a, b;
    stack s;
    initstack(&s);
    while (eq[i]){
        switch (eq[i]){
            case '!':
                getstack(&s, &a);
                putstack(&s, not(a));
                break;
            case '+':
                getstack(&s, &b);
                getstack(&s, &a);
                putstack(&s, or(a,b));
                break;
            case '*':
                getstack(&s, &b);
                getstack(&s, &a);
                putstack(&s, and(a,b));
                break;
            case '0':
            case '1':
                putstack(&s, eq[i]);
                break;
            default:
                freestack(&s);
                return -1;
        }
        i++;
    }
    if (emptystack(&s)){
        return -1;
    }else{
        getstack(&s, &a);
        freestack(&s);
        return a - '0';
    }
}
void free_table(char **t, int n, int m){
    for (int i = 0; i<n; i++){
        free(t[i]);
    }
    free(t);
}
char **calc_table(char *rpn, char *vars, int *n, int *m){
    sort(vars);
    int cols = get_len(vars);
    if (cols == 0 || cols >5) return NULL;
    int rows = (1<<cols)+1;
    cols++;
    char **table = (char **)malloc(rows*sizeof(char*));
    for (int i = 0; i<rows; i++)
        table[i] = (char *)malloc(cols*sizeof(char));
    int len = get_len(rpn);
    for (int i = 0; i<cols-1; i++){
        table[0][i] = vars[i];
        table[1][i] = '0';
    }
    table[0][cols-1] = '=';
    char carry;
    for (int i = 2; i<rows; i++){
        carry = '1';
        for (int j = cols-2; j>=0; j--){
            table[i][j] = xor(table[i-1][j], carry);
            carry = and(table[i-1][j], carry);
        }
    }
    char var;
    int tmp_res;
    for (int i = 1; i<rows; i++){
        char *tmp = copy(rpn, len);
        for (int j = 0; j<cols-1; j++){
            var = vars[j];
            for (int k = 0; k<len; k++){
                if (tmp[k] == var){
                    tmp[k] = table[i][j];
                }
            }
        }
        tmp_res = calculator(tmp);
        if (tmp_res == -1){
            free_table(table, rows, cols);
            return NULL;
        }
        table[i][cols-1] =  tmp_res + '0';
        free(tmp);
    }
    *n = rows;
    *m = cols;
    return table;
}
