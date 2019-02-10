#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
const char tree_ok=0;
const char tree_memerror=1;
const char tree_under=2;



tree* node_init(){
    tree* temp_pointer;
    temp_pointer=(tree*)malloc(sizeof(tree));
    if(temp_pointer==NULL){
        tree_error=tree_memerror;
    }
    temp_pointer->data=0;
    temp_pointer->left_son=NULL;
    temp_pointer->right_son=NULL;
    return temp_pointer;
}

void node_write(tree *t,base_type e){
    t->data=e;
}

void node_read(tree *t,base_type *e){
    *e=t->data;
}

int check_left_son(tree *t){
    return !(t->left_son==NULL);
}

int check_right_son(tree *t){
    return !(t->right_son==NULL);
}

int tree_empty(tree *t){
    return((!(check_left_son(t))&&(!(check_left_son(t))&&t->data!=0)));
}

void move_left(tree *t){
    t=t->left_son;
}

void move_right(tree *t){
    t=t->right_son;
}

void tree_data_set(tree* t,int data){
    t->data=data;
}

unsigned count_node_lvl(tree *t,char lvl){
    unsigned count_node(tree *t,char lvl,int i){
        static unsigned count=0;
        if(t==NULL) return 0;
        else if(i==lvl){
            return 1;
        }
        else{
            count+=count_node(t->left_son,lvl,i+1);
            count+=count_node(t->right_son,lvl,i+1);
        }
        return (i>0)?0:count;}
     return count_node(t,lvl,0);
}
