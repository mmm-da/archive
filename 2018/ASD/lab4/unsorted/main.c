#include <stdlib.h>
#include <stdio.h>
#include "search.h"
#include "unsorted_table.h"
int main(){
    table* t1,*t2;
    srand(rand());
    for(int size=50;size<=450;size+=50){
        t1=table_init(size);
        t2=table_init(size);
        fill_table(t1,size);
        fill_table(t2,size);
        switch_search(1);
        search_function(t1,size/2);
        printf("Linear search do in %d operation for %d elements\n",counter,size);
        switch_search(2);
        search_function(t2,size/2);
        printf("Fast linear search do in %d operation for %d elements\n",counter,size);
        printf("\n\n");
        table_done(t1);
        table_done(t2);
    }
    for(int size=50;size<=450;size+=50){
        t1=table_init(size);
        t2=table_init(size);
        fill_table(t1,size);
        fill_table(t2,size);
        switch_search(1);
        search_function(t1,size);
        printf("Linear search do in %d operation for %d elements\n",counter,size);
        switch_search(2);
        search_function(t2,size);
        printf("Fast linear search do in %d operation for %d elements\n",counter,size);
        printf("\n\n");
        table_done(t1);
        table_done(t2);
    }
    return 0;
}
