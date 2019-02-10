#include "task.h"
char* read_permise(unsigned count_of_permise){
    char* result_str=(char*)malloc(count_of_permise*sizeof(char)*50);
    char temp[50];
    int j,k=0;
    for(int i=0;i<count_of_permise;i++){
        scanf("%s",temp);
        fflush(stdin);
        j=0;
        result_str[k]='(';
        k++;
        while(temp[j]!='\0'){
            result_str[k]=temp[j];
            k++;
            j++;
        }
        result_str[k]=')';
        k++;
        result_str[k]='*';
        k++;
    }
    result_str[k-1]='\n';
    return result_str;
}

char* table_to_pknf_str(char **table,unsigned n,unsigned m){
    char *result_str=(char*)malloc(n*m*sizeof(char)*2);
    int j=0;
    for(int i=1;i<n;i++){
        if(table[i][m-1]=='0'){
            result_str[j]='(';
            j++;
            for(int k=0;k<m-1;k++){
                if(table[i][k]=='1'){
                    result_str[j]='!';
                    j++;
                }
                result_str[j]=table[0][k];
                j++;
                result_str[j]='+';
                j++;
            }
            j--;
            result_str[j]=')';
            j++;
            result_str[j]='*';
            j++;
        }
    }
    result_str[j-1]='\0';
    return result_str;
}

char* table_to_pdnf_str(char **table,unsigned n,unsigned m){
    char *result_str=(char*)malloc(n*m*sizeof(char)*2);
    int j=0;
    for(int i=1;i<n;i++){
        if(table[i][m-1]=='1'){
            result_str[j]='(';
            j++;
            for(int k=0;k<m-1;k++){
                if(table[i][k]=='0'){
                    result_str[j]='!';
                    j++;
                }
                result_str[j]=table[0][k];
                j++;
                result_str[j]='*';
                j++;
            }
            j--;
            result_str[j]=')';
            j++;
            result_str[j]='+';
            j++;
        }
    }
    result_str[j-1]='\0';
    return result_str;
}

char** table_to_pknf_arr(char **table,unsigned n,unsigned m,unsigned *count){
    char **result_str_arr=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n+1;i++){
        result_str_arr[i]=(char*)malloc(2*m*sizeof(char));
    }
    int j,p=0;
    for(int i=1;i<n;i++){
        j=0;
        if(table[i-1][m-1]=='0'){
            result_str_arr[p][j]='(';
            j++;
            for(int k=0;k<m-1;k++){
                if(table[i][k]=='1'){
                    result_str_arr[p][j]='!';
                    j++;
                }
                result_str_arr[p][j]=table[0][k];
                j++;
                result_str_arr[p][j]='+';
                j++;
            }
            j--;
            result_str_arr[p][j]=')';
            j++;
            result_str_arr[p][j]='\0';
            p++;
        }
    }
    *count=p;
    return result_str_arr;
}

void print_consequences(char* str){
    char varlist[50];
    char *rpn = NULL;
    rpn = to_rpn(str,varlist);
    int n, m;
    char **t = calc_table(rpn, varlist, &n, &m);
    if (t == NULL){
        printf("Invalid expression\n");
        exit(1);
    }
    unsigned counter;
    char** pknf_arr=table_to_pknf_arr(t,n,m,&counter);
    for(int i=0;i<counter;i++){
        //printf("%s\n",pknf_arr[i]);
    }
    unsigned count_of_consequences = pow(2, counter);
    for (int i = 0; i < count_of_consequences;i++){
        for (int j=0;j<counter;j++){
            if ( i & (1 << j) ) //--если j-й бит установлен
               printf("%s+",pknf_arr[j]);} //--то выводим j-й элемент множества
        printf("\b \n");
    }
}
