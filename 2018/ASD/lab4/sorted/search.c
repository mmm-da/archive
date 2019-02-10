#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned counter=0;


int linear_search(table* t,table_key_type key){
    counter=0;
    unsigned i;
    for(i=0;i<t->pointer && t->buffer[i].key != key;i++){}
    counter=2*i+1;
    if(i==t->pointer){
        table_error=table_key_not_exist;
        return -1;
    }
    return i;
}

int fast_linear_search(table* t,table_key_type key){
    counter=0;
    unsigned i;
    t->size++;
    t->buffer[t->size].key=key;
    for(i=0;t->buffer[i].key != key;i++){}
    counter=i+1;
    if(i==t->pointer){
        table_error=table_key_not_exist;
        t->size--;

        return -1;
    }
    t->size--;
    return i;
}


int fast_linear_sort_search(table* t,table_key_type key){
    counter=0;
    unsigned i;
    t->size++;
    t->buffer[t->pointer].key=key;
    for(i=0;t->buffer[i].key<=key;i++){
    if(t->buffer[i].key==key && i!=t->pointer){
        counter=i;
        t->size--;
        return i;
    }}
    t->size--;
    return -1;
}

int binary_search(table* t,table_key_type key){
    counter=0;
    unsigned i, mid;
    unsigned first = 0;
    unsigned last = t->size;
    do{
        mid=first+(last-first)/2;
        if(t->buffer[mid].key==key){
            return mid;
            counter++;
        }
        if(t->buffer[mid].key>key){
            last = mid -1;
            counter++;
        }
        else{
            first = mid + 1;
            counter++;
        }

    }while(last>=first);
    return -1;
}



int ls(table* t, int i, int n, table_key_type key){
    for (i; i < n && (t->buffer[i].key) != key; i++) counter += 3;
    if (i < n) counter += 3;
    else counter++;
    return (i < n ? i : -1);
}

int block_search(table* t, table_key_type key){
    counter = 0;
    int n=t->size;
    int i, h, x = (int)round(sqrt(n));
    h = (int)round(n/x);
    for (i = h - 1; i < n && (t->buffer[i].key) < key; i += h) counter+= 3;
        if (i < n) counter+= 3;
        else counter++;
    int j;
    if (i < n){
        j = ls(t, i-h+1, (i+1)*h, key);
        if (j != -1){
            return j;
        }
    }
    j = i - h + 1;
    if (j < n){
        j = ls(t, j, n, key);
        if (j != -1){
            return j;
        }
    }
    return -1;
}
