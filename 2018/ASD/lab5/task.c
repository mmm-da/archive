#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "list.h"
#include <string.h>

list* str_to_list(char* str){
    list *poly;
    poly=list_init(strlen(str)/2);
    node temp;
    char flag;
    pos_move_to_first(poly);
    int i=0;
    while(str[i]!='\0'){
        temp.a=0;
        temp.exp=0;
        while((str[i]>='0')&&(str[i]<='9')){
            temp.a+=str[i]-'0';
            temp.a*=10;
            i++;
        }
        temp.a=temp.a/10;
        i+=2;
        while((str[i]>='0')&&(str[i]<='9')){
            temp.exp+=str[i]-'0';
            temp.exp*=10;
            i++;
        }
        temp.exp=temp.exp/10;
        if(str[i]=='+') i++;
        if(temp.a!=0) {
            list_put(poly,temp);
            list_next(poly);
        }
    }
    return poly;
}

list* sum_poly(list* poly1,list* poly2){
    list* result=list_sum(poly1,poly2);
    list_base_type temp1,temp2;
    for(int i=0;i<result->list_lenght-1;i++){
        list_move_to(result,i);
        temp1=list_read(result);
        for(int j=i+1;j<result->list_lenght;j++){
            list_move_to(result,j);
            temp2=list_read(result);
            if(temp1.exp==temp2.exp){
                list_move_to(result,j-1);
                list_get(result);
                list_move_to(result,i);
                result->pos_current->data.a+=temp2.a;
            }
        }
    }
    return result;
}

void print_poly(list* polynom){
    pos_move_to_first(polynom);
    list_next(polynom);
    while(!(list_end(polynom))){
        printf("%dx^%d",polynom->pos_current->data.a,polynom->pos_current->data.exp);
        if(polynom->pos_current->next!=NULL){
            printf("+");
        }
        list_next(polynom);
    }
    printf("%dx^%d\n",polynom->pos_current->data.a,polynom->pos_current->data.exp);
}
