#include <stdio.h>
#include <stdlib.h>
#include "list.h"


const char list_ok = 0;
const char list_mem_error = 1;
const char list_over = 2;
const char list_under = 3;

char task_input(FILE *f_in, base_type *t){
    fscanf(f_in, "%s %u %u", &t->name, &t->time, &t->type);
    return t->type;
}


void task_out(base_type t){
    printf("(%s %u %u)", t.name, t.time, t.type);
}

list* list_init(unsigned size){
    list_error=list_ok;
    list* new_list;
    element* fake;
    new_list=(list*)malloc(sizeof(list));
    fake=(element*)malloc(sizeof(element));
    new_list->pos_start=fake;
    new_list->pos_current=fake;
    new_list->list_lenght=0;
    new_list->list_size=size;
    return new_list;
}

void list_put(list *l, list_base_type e){
    element* new_element=element_gen(e);
    new_element->data=e;
    new_element->next=l->pos_current->next;
    l->pos_current->next=new_element;
    l->list_lenght++;
}

list_base_type list_get(list *l){
    list_base_type temp;
    if(l->list_lenght!=1){
        temp=l->pos_current->next->data;
        l->pos_current->next=l->pos_current->next->next;
        l->list_lenght--;
    }
    else{
        l->list_lenght--;
        temp=l->pos_current->data;
        l->pos_current=l->pos_start;
        l->pos_current->next=NULL;
    }
    return temp;
}

list_base_type list_read(list *l){
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
    if(!list_empty(l)){
    while(!(list_end(l))){
        list_next(l);
    }}
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

void list_done(list *l){
    free(l);
}

element* element_gen(list_base_type data){
    element* temp;
    temp=(element*)malloc(sizeof(element));
    temp->data=data;
    temp->next=NULL;

    return temp;
}
