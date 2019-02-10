#include "lex_checker.h"

char *op_names[8] ={{"CLR"},{"IN"},{"OUT"},{"MOV"},{"SUB"},{"ADD"},{"DIV"},{"MLT"}};

char* get_word(const char *str, unsigned *k){
    int j=0;
    int i=*k;
    char* word=(char*)malloc(sizeof(char)*10);
    while((str[i]==' ')&&(str[i]!='\n')){
        i++;
    }
    while((str[i]!=' ')&&(str[i]!='\0')&&(str[i]!='\n')){
        word[j]=str[i];
        i++;
        j++;
    }
    *k=i;
    word[j]='\0';
    return word;
}

int token_input(FILE *f_in, char *str){
    if ( fgets (str , 100 , f_in) != NULL ){
        return 1;
    }
    return 0;
}

token_op* get_operator(char* str){
    unsigned current_char=0;
    token_op *temp=(token_op*)malloc(sizeof(token_op));
    char flag=1,i=0;
    char* op_name=get_word(str,&current_char);
    while((i<8)&&(flag)){
        if((strcmp(op_name,op_names[i]))==0){
            temp->op_type=i;
            flag=0;
        }
        i++;
    }
    if(flag){
        printf("Sintax error\n");
        temp->op_type=-1;
    }
    if((temp->op_type==1)||(temp->op_type==2)){
        temp->var_1=(token_var*)malloc(sizeof(token_var));
        char* str_1=get_word(str,&current_char);
        if(check_var(str_1)){
            temp->var_1_state=1;
            temp->var_1->name=str_1;
        }
        else{
            temp->var_1_state=2;
            temp->var_1->value=atof(str_1);
            temp->var_1->name=NULL;
        }
    }
    if(temp->op_type>2){
        temp->var_1=(token_var*)malloc(sizeof(token_var));
        char* str_1=get_word(str,&current_char);
        if(check_var(str_1)){
            temp->var_1_state=1;
            temp->var_1->name=str_1;
        }
        else{
            temp->var_1_state=2;
            temp->var_1->value=atof(str_1);
            temp->var_1->name=NULL;
        }
        temp->var_2=(token_var*)malloc(sizeof(token_var));
        char* str_2=get_word(str,&current_char);
        if(check_var(str_2)){
            temp->var_2_state=1;
            temp->var_2->name=str_2;
        }
        else{
            temp->var_2_state=2;
            temp->var_2->value=atof(str_2);
            temp->var_2->name=NULL;
        }
    }
    return temp;
}

char check_var(char* str){
    int i=0;
    int flag=1;
    while((str[i]!='\0')&&flag){
        if((str[i]<='0')&&(str[i]>='9')){
            flag=0;
        }
        i++;
    }
    return flag;
}


void token_run(token_op* op,table* var_table){
    token_var *temp1,*temp2;
    switch (op->op_type) {
        case OP_ERROR: printf("Syntax error\n");
            exit(-1);
            break;
        case OP_CLR: printf("Reset all\n");
            table_done(var_table);
            var_table=table_init(VAR_COUNT);
            break;
        case OP_IN:
            if(op->var_1_state=1){
                float temp;
                printf("Input value of %s - ",op->var_1->name);
                scanf("%f",&temp);
                op->var_1->value=temp;
                if(table_element_search(var_table,op->var_1->name,hash_func1,hash_func2)){
                    table_element_edit(var_table,op->var_1->name,op->var_1,hash_func1,hash_func2);
                }
                else{
                    table_put(var_table,op->var_1,hash_func1,hash_func2);
            }}
            break;
        case OP_OUT:
            if(op->var_1_state=1){
                if(table_element_search(var_table,op->var_1->name,hash_func1,hash_func2)){
                    op->var_1=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    printf("%s = %f\n",op->var_1->name,op->var_1->value);
                }
            }
            else{
                if(op->var_1_state=2){
                printf("%f\n",op->var_1->value);
                }
            }
            break;
        case OP_MOV:
            if(op->var_2_state=1){
                if(table_element_search(var_table,op->var_2->name,hash_func1,hash_func2)){
                    temp2=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    table_element_edit(var_table,op->var_1->name,temp2,hash_func1,hash_func2);
                }
            }
            else{
                if(op->var_2_state=2){
                    table_element_edit(var_table,op->var_1->name,op->var_2,hash_func1,hash_func2);
                }
            }
            break;
        case OP_SUB:
            if(op->var_2_state=1){
                if(table_element_search(var_table,op->var_2->name,hash_func1,hash_func2)){
                    temp2=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    temp1=table_read(var_table,op->var_2->name,hash_func1,hash_func2);
                    temp2->value=temp1->value-temp2->value;
                    table_element_edit(var_table,op->var_1->name,temp2,hash_func1,hash_func2);
                }
            }
            else{
                if(op->var_2_state=2){
                    temp1=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    temp1->value=temp1->value-op->var_2->value;
                    table_element_edit(var_table,op->var_1->name,op->var_2,hash_func1,hash_func2);
                }
            }
            break;
        case OP_ADD:
            if(op->var_2_state=1){
                if(table_element_search(var_table,op->var_2->name,hash_func1,hash_func2)){
                    temp2=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    temp1=table_read(var_table,op->var_2->name,hash_func1,hash_func2);
                    temp2->value=temp1->value+temp2->value;
                    table_element_edit(var_table,op->var_1->name,temp2,hash_func1,hash_func2);
                }
            }
            else{
                if(op->var_2_state=2){
                    temp1=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    temp1->value=temp1->value+op->var_2->value;
                    table_element_edit(var_table,op->var_1->name,op->var_2,hash_func1,hash_func2);
                }
            }
            break;
        case OP_DIV:
            if(op->var_2_state=1){
                if(table_element_search(var_table,op->var_2->name,hash_func1,hash_func2)){
                    temp2=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    temp1=table_read(var_table,op->var_2->name,hash_func1,hash_func2);
                    temp2->value=temp1->value/temp2->value;
                    table_element_edit(var_table,op->var_1->name,temp2,hash_func1,hash_func2);
                }
            }
            else{
                if(op->var_2_state=2){
                    temp1=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    temp1->value=temp1->value/op->var_2->value;
                    table_element_edit(var_table,op->var_1->name,op->var_2,hash_func1,hash_func2);
                }
            }
            break;
        case OP_MLT:
            if(op->var_2_state=1){
                if(table_element_search(var_table,op->var_2->name,hash_func1,hash_func2)){
                    temp2=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    temp1=table_read(var_table,op->var_2->name,hash_func1,hash_func2);
                    temp2->value=temp1->value*temp2->value;
                    table_element_edit(var_table,op->var_1->name,temp2,hash_func1,hash_func2);
                }
            }
            else{
                if(op->var_2_state=2){
                    temp1=table_read(var_table,op->var_1->name,hash_func1,hash_func2);
                    temp1->value=temp1->value*op->var_2->value;
                    table_element_edit(var_table,op->var_1->name,op->var_2,hash_func1,hash_func2);
                }
            }
            break;
        default: printf("Error\n");
            exit(-2);
    }
}
