#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <string.h>
int i=0;
int temp_i=0;
int print_count=1;
char str[255]="ABCD..E..F..G.HI..J..";

void build_node(tree* t){
    fflush(stdout);
    if(str[i]!='\0'){
        if(str[i]!='.'){
            t=node_init();
            t->data=str[i];
            i++;
            build_node(t->left_son);
            i=temp_i+1;
            build_node(t->right_son);
        }
        temp_i=i;
    }
}

void revers_print_str(char* str){
    int str_len=strlen(str);
    for(i=str_len;i--;i>0){
        printf("%c",str[i]);
    }
    printf("\n");
}

void tree_paths_print(tree *t){
    char print_str[255];
    static int k=0;
    printf("%c\n",t->data);
    print_str[k]=t->data;
    if(!(check_left_son(t) && check_right_son(t))){
       printf("%d.",print_count);
       print_count++;
       revers_print_str(print_str);
    }
    else
    {
        if(check_left_son(t)){
            k++;
            tree_paths_print(t->left_son);
        }
        if(check_right_son(t)){
            k++;
            tree_paths_print(t->right_son);
        }
    }
}

int main(){
    tree *t;
    tree *start_node;
    char lvl=1;
    printf("%s\n",str);
    build_node(t);
    printf("count node on lvl %d - %d\n",lvl,count_node_lvl(t,lvl));
    tree_paths_print(t);
        getchar();
    return 0;
}
