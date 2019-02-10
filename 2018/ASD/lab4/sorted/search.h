#ifndef SEARCH_H_
#define SEARCH_H_
#include "sorted_table.h"

extern unsigned counter;

int linear_search(table* t,table_key_type key);
int fast_linear_search(table* t,table_key_type key);
int fast_linear_sort_search(table* t,table_key_type key);
int binary_search(table* t,table_key_type key);
int ls(table* t, int i, int n, table_key_type key);
int block_search(table* t,table_key_type key);


#endif
