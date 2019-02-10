#ifndef UNSORTED_TABLE_H_
#define UNSORTED_TABLE_H_
#include "search.h"

extern const int table_ok; //
extern const int table_over; // Таблица переполнена
extern const int table_under; // Таблица пуста
extern const int table_key_not_exist; // Ключ таблицы не существует
extern const int table_mem_error; // Ошибка выделения памяти для таблицы

int table_error;

    typedef int table_data_type;
    typedef int table_key_type;
    typedef struct {
        table_data_type data;
        table_key_type key;
    } element;

    typedef struct {
        element* buffer;
        unsigned pointer;
        unsigned size;
    } table;

    typedef int(*s_function)(table*,table_key_type);
    s_function search_function;


    table* table_init(unsigned size);
    void table_put(table* t,element e);
    void table_get(table* t,element* e,table_key_type key_num);
    char table_empty(table* t);
    char table_full(table* t);
    void switch_search(int mode);
    void fill_table(table *t, unsigned size);
    void table_done(table *t);


#endif
