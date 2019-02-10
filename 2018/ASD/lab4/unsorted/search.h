#ifndef SEARCH_H_
#define SEARCH_H_
#include "unsorted_table.h"

extern unsigned counter;


int linear_search(table* t,table_key_type key);
int fast_linear_search(table* t,table_key_type key);

int fast_linear_sort_search(table* t,table_key_type key);
int binary_search(table* t,table_key_type key);
int block_search(table* t,table_key_type key);

#endif
