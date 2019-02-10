#ifndef TASK
#define TASK

int expn(int e);
void fill_table(char **table, int column, int row, int count);
char** table_Init(int size);
void create_calcStr(char* str,char** table, int line,char* r);
void task_1(char* str,int size);
void task_2(char* str,int size);
void task_5(char* str,int size);
char rn_Calc(char* str);
#endif
