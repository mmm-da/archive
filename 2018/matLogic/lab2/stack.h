#ifndef STACK_H
#define STACK_H

typedef struct _element *ptrel;
typedef struct _element{
    char data;
    ptrel next;
}element;

typedef struct _stack{
    ptrel head;
}stack;

void initstack(stack *s);
int emptystack(stack *s);
void putstack(stack *s, char data);
void getstack(stack *s, char *data);
void freestack(stack *s);

#endif /* STACK_H */
