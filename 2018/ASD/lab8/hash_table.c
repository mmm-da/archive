#include "hash_table.h"
#include <math.h>
int table_error;

const char table_ok = 0;
const char table_mem_err = 1;
const char table_under = 2;

unsigned hash_func1(char* a){
    int i=0,c1=3,c2=5,hash_result=0;
    while(a[i]!='\0'){
        hash_result+=a[i];
        i++;
    }
    hash_result=abs((c1*hash_result+c2) % VAR_COUNT);
    return hash_result;
}

unsigned hash_func2(char* a){
    int i=0,c=10,hash_result=0;
    while(a[i]!='\0'){
        hash_result+=a[i];
        i++;
    }
    hash_result=abs((hash_result + c) % VAR_COUNT);
    return hash_result;
}

table* table_init(unsigned table_size){
    table* temp=(table*)malloc(sizeof(table));
    if(temp!=NULL){
        temp->table_size=table_size;
        temp->table_current_size=0;
        temp->table_buffer=(table_el*)malloc(sizeof(table_el)*table_size);
        if(temp->table_buffer==NULL){
            table_error=table_mem_err;
            return;
        }
        table_error=table_ok;
        return temp;
    }
    else{
        table_error=table_mem_err;
        return;
    }
}

int table_empty(table *t){
    return t->table_current_size==0;
}

int table_put(table *t, token_var *e, hash_func f1,hash_func f2){
    int i=0;
    //хеш ключа
    int hash_val=f1(e->name);
    //смещение в массиве
    int step_val=f2(e->name);
    while((t->table_buffer[hash_val].e!=NULL)&&(t->table_buffer[hash_val].flag!=-1)&&(i<100)){
        hash_val+=step_val % VAR_COUNT;
        hash_val%=VAR_COUNT;
        i++;
    }
    //остановка после 100 попыток внести элемент в таблицу
    if(i>=100){
        printf("can't find empty space for element\n");
        return 1;
    }
    t->table_buffer[hash_val].e=e;
    t->table_buffer[hash_val].flag=1;
    return 0;
}

token_var* table_read(table *t, char *key, hash_func f1,hash_func f2){
    int i=0;
    token_var *temp;
    int hash_val=f1(key);
    int step_val=f2(key);
    while((t->table_buffer[hash_val].e!=NULL)&&(i<100)){
        if(!strcmp(key,t->table_buffer[hash_val].e->name)){
            return t->table_buffer[hash_val].e;
        }
        hash_val+=step_val % VAR_COUNT;
        hash_val%=VAR_COUNT;
        i++;
    }
    if(i>=100){
        printf("can't find element\n");
        return NULL;
    }
    printf("not match\n");
    return NULL;
}

token_var* table_get(table *t, char *key, hash_func f1,hash_func f2){
    int i=0;
    token_var *temp;
    int hash_val=f1(key);
    int step_val=f2(key);
    while((t->table_buffer[hash_val].e!=NULL)&&(i<100)){
        if(!strcmp(key,t->table_buffer[hash_val].e->name)){
            temp=t->table_buffer[hash_val].e;
            t->table_buffer[hash_val].e==NULL;
            t->table_buffer[hash_val].flag=-1;
            return temp;
        }
        hash_val+=step_val % VAR_COUNT;
        hash_val%=VAR_COUNT;
        i++;
    }
    if(i>=100){
        printf("can't find element\n");
        return NULL;
    }
    return NULL;
}

int table_element_edit(table *t, char *key,token_var *e, hash_func f1,hash_func f2){
    int i=0;
    token_var *temp;
    int hash_val=f1(key);
    int step_val=f2(key);
    while((t->table_buffer[hash_val].e!=NULL)&&(i<100)){
        if(!strcmp(key,t->table_buffer[hash_val].e->name)){
            t->table_buffer[hash_val].e=e;
            return 0;
        }
        hash_val+=step_val % VAR_COUNT;
        hash_val%=VAR_COUNT;
        i++;
    }
    if(i>=100){
        printf("can't find element\n");
        return 1;
    }
    return 1;
}

void table_done(table *t){
    free(t->table_buffer);
    free(t);
}

int table_element_search(table *t, char *key,hash_func f1,hash_func f2){
    int i=0;
    token_var *temp;
    int hash_val=f1(key);
    int step_val=f2(key);
    while((t->table_buffer[hash_val].e!=NULL)&&(i<100)){
        if(!strcmp(key,t->table_buffer[hash_val].e->name)){
            return 1;
        }
        hash_val+=step_val;
        hash_val%=VAR_COUNT;
        i++;
    }
    if(i>=100){
        printf("can't find element\n");
        return 0;
    }
    return 0;
}
