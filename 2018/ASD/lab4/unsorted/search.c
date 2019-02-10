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
    t->buffer[t->pointer].key=key;
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
    for(i=0;t->buffer[i].key<key;i++){}
    counter=i;
    if(t->buffer[i].key==key && i!=t->pointer){
        t->size--;
        return i;

    }
    t->size--;
    return -1;
}

int binary_search(table* t,table_key_type key){
    counter=0;
    unsigned i, mid;
    unsigned left = 0;
    unsigned right = t->size;
    while(left <= right){
        mid = (left+right)/2;
        if (t->buffer[mid].key==key){
            return mid;
        }
        counter+=2;
        if (t->buffer[mid].key>key) right = mid-1;
        else left = mid +1;
    }
    return -1;
}



int ls(table *t, table_key_type key,unsigned start, unsigned finish){
    unsigned i=start;
    while(i<finish && t->buffer[i].key!=key) i++;
    counter+=i;
    if(i==t->pointer){
        table_error=table_key_not_exist;
        return -1;
    }
    else return i;

}

int b_search(table *t, table_key_type key, unsigned block_size){
    counter=0;
    unsigned i=0;
    while(i<t->size){
        if(t->buffer[i+block_size].key>key){
            counter++;
            return ls(t,key,i,i+block_size);
        }
    i+=block_size;
    }
    if(i>=t->size && t->buffer[t->size-1].key>key){
        return ls(t,key,i-block_size,t->size-1);
    }
}

int block_search(table* t,table_key_type key){
    unsigned block_size = (unsigned)sqrt(t->size);
    return b_search(t, key, block_size);
}
