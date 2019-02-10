#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VAR_COUNT 255
extern const char table_ok;
extern const char table_mem_err;
extern const char table_under;

typedef struct var{
    char* name;
    float value;
}token_var;
typedef struct el{
    token_var* e;
    int flag; /* flag =-1 — элемент массива был занят
                 flag = 0 — элемент массива свободен
                 flag = 1 — элемент массива занят */
}table_el;
typedef struct t{
    table_el *table_buffer;
    unsigned table_size;
    unsigned table_current_size;
}table;
typedef unsigned (* hash_func)(char*);
unsigned hash_func1(char* a);
unsigned hash_func2(char* a);
table* table_init(unsigned table_size);
int table_empty(table *t); // Возвращает 1 , если таблица пуста, иначе — 0
int table_put(table *t, token_var *e, hash_func f1,hash_func f2); // Включение элемента в таблицу.
token_var* table_get(table *t, char *key, hash_func f1,hash_func f2);  // Исключение элемента.
token_var* table_read(table *t, char *key, hash_func f1,hash_func f2);// Чтение элемента.
int table_element_edit(table *t, char *key,token_var *e, hash_func f1,hash_func f2); // Изменение элемента таблицы
int table_element_search(table *t,char *key, hash_func f1,hash_func f2);
void table_done(table *t);
#endif
