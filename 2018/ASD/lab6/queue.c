#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"
const char queue_ok = 1;
const char queue_under = 2;
const char queue_over = 3;
const char queue_mem_error = 4;

queue* queue_init(unsigned size){
    list* temp_pointer;
    temp_pointer=list_init(size);
    if(temp_pointer==NULL){
        queue_error=queue_mem_error;
        exit(queue_error);
    }
    queue_error=queue_ok;
    return temp_pointer;
}
void queue_put(queue *q, base_type e){
    if(queue_full(q)){
        queue_error=queue_over;
        exit(queue_error);
    }
    pos_move_to_last(q);
    list_put(q,e);
}
 base_type queue_get(queue *q){
    if(queue_empty(q)){
        queue_error=queue_under;
        exit(queue_error);
    }
    pos_move_to_first(q);
    list_next(q);
    base_type temp;
    temp=list_get(q);
    return temp;
}
 base_type queue_read(queue *q){
    if(queue_empty(q)){
        queue_error=queue_under;
        exit(queue_error);
    }
    pos_move_to_first(q);
    list_next(q);
    base_type temp;
    temp=list_read(q);
    return temp;
}
void queue_print(queue *q){
    if(q->list_lenght==0){
        printf("empty \n");
    }
    else{
        pos_move_to_first(q);
        list_next(q);
        for(int i=0;i<q->list_lenght;i++){
            task_out(list_read(q));
            printf(", ");
            list_next(q);
            printf("\n");
        }
    }
}
int queue_empty(queue *q){
    return list_empty(q);
}
int queue_full(queue *q){
    return list_full(q);
}
void queue_done(queue *q){
    list_done(q);
}
