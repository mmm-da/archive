#include <stdio.h>
#include <stdlib.h>
#include "list.h"


const char list_ok = 0;
const char list_mem_error = 1;
const char list_over = 2;
const char list_under = 3;

list* list_init(unsigned size){
    list_error=list_ok;
    list* new_list;
    element* fake;
    new_list=(list*)malloc(sizeof(list));
    if(new_list==NULL){
        list_error=list_mem_error;
        exit(list_error);
    }
    fake=(element*)malloc(sizeof(element));
    new_list->pos_start=fake;
    new_list->pos_current=fake;
    new_list->list_lenght=0;
    new_list->list_size=size;
    return new_list;
}

void list_put(list *l, list_base_type e){
    if(list_full(l)){
        list_error=list_over;
        exit(list_error);
    }
    element* new_element=element_gen(e);
    new_element->data=e;
    new_element->next=l->pos_current->next;
    l->pos_current->next=new_element;
    l->list_lenght++;
}

list_base_type list_get(list *l){
    if(list_empty(l)){
        list_error=list_under;
        exit(list_error);
    }
    if(list_end(l)){
        list_error=list_under;
        exit(list_error);
    }
    list_base_type temp;
    temp=l->pos_current->next->data;
    l->pos_current->next=l->pos_current->next->next;
    l->list_lenght--;
    return temp;
}

list_base_type list_read(list *l){
    if(list_empty(l)){
        list_error=list_under;
        exit(list_error);
    }
    return l->pos_current->data;
}

int list_full(list *l){
    return l->list_lenght>=l->list_size;
}

int list_empty(list *l){
    return l->list_lenght==0;
}

int list_end(list *l){
    return l->pos_current->next==NULL;
}

unsigned list_count(list *l){
    return l->list_lenght;
}

void pos_move_to_first(list *l){
    l->pos_current=l->pos_start;
}

void pos_move_to_last(list *l){
    while(!(list_end(l))){
        list_next(l);
    }
}

void list_next(list *l){
    if(l->pos_current->next!=NULL){
        l->pos_current=l->pos_current->next;
    }
    else{
        list_error=list_under;
        printf("error %d\n",list_under);
        exit(list_error);
    }
}

void list_move_to(list *l, unsigned int index){
    if(index+1>l->list_lenght){
        list_error=list_under;
        exit(list_error);
    }
    pos_move_to_first(l);
    for(int i=0;i<index+1;i++) list_next(l);
}

void list_done(list *l){
    free(l);
}

list* list_sum(list *list_1,list *list_2){
    list* res=list_init(list_2->list_size+list_1->list_size+1);
    pos_move_to_first(list_1);
    pos_move_to_first(list_2);
    list_base_type temp;
    list_next(list_1);
    list_next(list_2);
    while(!(list_end(list_1))){
        temp=list_read(list_1);
        list_put(res,temp);
        list_next(res);
        list_next(list_1);
    }
    temp=list_read(list_1);
    list_put(res,temp);
    list_next(res);
    while(!(list_end(list_2))){
        temp=list_read(list_2);
        list_put(res,temp);
        list_next(res);
        list_next(list_2);
    }
    temp=list_read(list_2);
    list_put(res,temp);
    list_next(res);
    return res;
}

element* element_gen(list_base_type data){
    element* temp;
    temp=(element*)malloc(sizeof(element));
    temp->data=data;
    temp->next=NULL;

    return temp;
}
