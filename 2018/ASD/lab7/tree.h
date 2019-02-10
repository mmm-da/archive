#ifndef TREE_H_
#define TREE_H_
#include <stdlib.h>
#include <stdio.h>
extern const char tree_ok;
extern const char tree_memerror;
extern const char tree_under;
typedef char base_type;
typedef struct e node;
typedef struct e{
    base_type data;
    node *left_son;
    node *right_son;
};
typedef node tree;
char tree_error;
tree* node_init(); // инициализация — создается элемент, который будет содержать корень дерева
void node_write(tree *t, base_type e); //запись данных
void node_read(tree *t,base_type *e);//чтение
void node_delete(tree *t);//удаление листа
void move_left(tree *t);//перейти к левому сыну
void move_right(tree *t);//перейти к правому сыну
int check_left_son(tree *t);//1 — есть левый сын, 0 — нет
int check_right_son(tree *t);//1 — есть правый сын, 0 — нет
int tree_empty(tree *t);//1 — пустое дерево,0 — не пустое
unsigned count_node_lvl(tree *t,char lvl);
void tree_data_set(tree* t,int data);
#endif
