#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "sorted_table.h"

const int table_ok = 0; //
const int table_over= 1; // Таблица переполнена
const int table_under=2; // Таблица пуста
const int table_key_not_exist=3; // Ключ таблицы не существует
const int table_mem_error=4; // Ошибка выделения памяти для таблицы



void fill_table(table *t, unsigned size){
  element e;
  for (unsigned i = 0; i<size; i++){
    e.key = i;
    table_put(t, e);
  }
}

table* table_init(unsigned size){
        table *temp_table;
        temp_table=(table*)malloc(sizeof(table));
        temp_table->buffer=(element*)malloc(sizeof(element)*size);
        if(temp_table == NULL){
            table_error=table_mem_error;
            exit(table_error);
        }
        temp_table->pointer=0;
        temp_table->size=size;
        switch_search(1);
        table_error=table_ok;
        return temp_table;
}

void table_put(table* t,element e){
    if(table_full(t)){
        table_error=table_over;
        exit(table_error);
    }
    int element_pos = search_function(t,e.key);
    if (element_pos !=-1){
        t->buffer[element_pos].data=e.data;
    }
    else{
        unsigned place= t->pointer;
        while(place>0 && t->buffer[place-1].key>e.key){
            t->buffer[place]=t->buffer[place-1];
            place--;
        }
        t->buffer[t->pointer]=e;
        t->pointer++;
    }
}

void table_get(table* t,element* e,table_key_type key_num){
    if (table_empty(t)){
        table_error=table_under;
        exit(table_error);
    }
    table_key_type element_pos = search_function(t,key_num);
    if (element_pos!= -1){
        e->data = t->buffer[element_pos].data;
        e->key = t->buffer[element_pos].key;
        unsigned place = element_pos;
        while(place != t->pointer-1){
            t->buffer[place]=t->buffer[place+1];
            place++;
        }
        t->pointer--;
    }
}

char table_empty(table* t){
    if(t->pointer == 0){
        return 1;
    }
    return 0;
}

char table_full(table* t){
    if(t->pointer == t->size){
        return 1;
    }
    return 0;
}

void switch_search(int mode){
    switch (mode) {
        case 2:
        search_function= binary_search;
        break;
        case 1:
        search_function=fast_linear_sort_search;
        break;
        case 3:
        search_function= block_search;
        break;
    }
}

void table_done(table *t){
    free(t->buffer);
    free(t);
}
