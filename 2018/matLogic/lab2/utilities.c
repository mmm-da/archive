#include <stdlib.h>
#include "utilities.h"
void print_table(char **table, int rows, int cols){
    for(int i = 0; i<rows; i++){
        for (int j = 0; j<cols; j++){
            printf("%c\t", table[i][j]);
        }
        printf("\n");
    }
}
int get_len(char *str){
    int len = 0;
    while(str[len]) len++;
    return len;
}
int in_str(char c, char *str){
    int pos = 0;
    while (str[pos] && str[pos] != c) pos++;
    if (str[pos] == c)
        return pos;
    else
        return -1;
}
void sort(char *str){
    char t;
    for (int i = 0; str[i] != '\0'; i++){
        for (int j = 0; str[j] != '\0'; j++){
            if (str[i] < str[j]){
                t = str[i];
                str[i] = str[j];
                str[j] = t;
            }
        }
    }
}
char *copy(char *s, int len){
    char *res = (char *)malloc(len*sizeof(char));
    for (int i = 0; i<=len; i++){
        res[i] = s[i];
    }
    return res;
}
