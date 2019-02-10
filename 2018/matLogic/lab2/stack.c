#include <stdlib.h>
#include "stack.h"
void initstack(stack *s){
    s->head = NULL;
}
int emptystack(stack *s){
    return s->head == NULL;
}
void putstack(stack *s, char data){
    ptrel tmp = (ptrel)malloc(sizeof(element));
    tmp->data = data;
    tmp->next = s->head;
    s->head = tmp;
}
void getstack(stack *s, char *data){
    if (!emptystack(s)){
        ptrel tmp = s->head;
        *data = tmp->data;
        s->head = tmp->next;
        free(tmp);
    }
}
void freestack(stack *s){
    char tmp;
    while (!emptystack(s)){
        getstack(s, &tmp);
    }
}
