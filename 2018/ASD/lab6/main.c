#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

typedef struct prc{
    char status;
    base_type task;
}processor;

int main(){
    processor p1,p2;
    p1.status=0;
    p2.status=0;
    stack *s=stack_init(50);
    queue *q1=queue_init(50),*q2=queue_init(50),*q3=queue_init(50);
    char clock_stop=0,input_flag=0;
    base_type task_in;
    FILE *file_in;
    int tick=0;
    char file_name[128];
    printf("File name?: ");
    scanf("%s", file_name);
    if ((file_in = fopen(file_name, "r"))==NULL){
        printf("Unable to open");
        return 1;
    }
    while(!clock_stop){
        printf("TICK %d\n",tick );
        //обработчики задач
        if((!p1.status==0)&&(p1.task.time!=0)){
            p1.task.time--;
            if(p1.task.time==0){
                p1.status=0;
            }
        }
        if((!p2.status==0)&&(p2.task.time!=0)){
            p2.task.time--;
            if(p2.task.time==0){
                p2.status=0;
            }
        }
        //планировщик
        if(!queue_empty(q1)){
            if(p1.status==3){
                if((p2.status==0)&&(queue_empty(q2))){
                    p2.task=p1.task;
                    p2.status=3;
                    p1.task=queue_get(q1);
                    p1.status=1;
                }
                else{
                    stack_put(s,p1.task);
                    p1.task=queue_get(q1);
                    p1.status=1;
                }
            }
            else{
                if(p1.status==1){
                    stack_put(s,queue_get(q1));
                }
                else{
                    p1.task=queue_get(q1);
                    p1.status=1;
                }
            }
        }
        if(!queue_empty(q2)){
            if(p2.status==3){
                if((p1.status==0)&&(queue_empty(q1))){
                    p1.task=p2.task;
                    p1.status=3;
                    p2.task=queue_get(q2);
                    p2.status=2;
                }
                else{
                    stack_put(s,p2.task);
                    p2.task=queue_get(q2);
                    p2.status=2;
                }
            }
            else{
                if(p2.status==2){
                    stack_put(s,queue_get(q2));
                }
                else{
                    p2.task=queue_get(q2);
                    p2.status=2;
                }
            }
        }
        if(!queue_empty(q3)){
            if((p1.status==0)&&(queue_empty(q1))){
                p1.task=queue_get(q3);
                p1.status=3;
            }
            if((p2.status==0)&&(queue_empty(q2))){
                p2.task=queue_get(q3);
                p2.status=3;
            }
        }
        if((queue_empty(q1))&&(queue_empty(q3))&&(p1.status==0)){
            if (!(stack_empty(s))){
            base_type temp_task=stack_read(s);
            if((temp_task.type==3)&&(temp_task.type==1)){
                p1.task=temp_task;
                p1.status=temp_task.type;
                stack_get(s);
            }}
        }
        if((queue_empty(q2))&&(queue_empty(q3))&&(p2.status==0)){
            if(!(stack_empty(s))){
            base_type temp_task=stack_read(s);
            if((temp_task.type==3)&&(temp_task.type==2)){
                p2.task=temp_task;
                p2.status=temp_task.type;
                stack_get(s);
            }}
        }
        //ввод задач
        fflush(stdin);
        if(!input_flag){
        switch (task_input(file_in,&task_in)) {
            case 0:{
                input_flag=1;
                break;}
            case 1:{
                queue_put(q1,task_in);
                break;}
            case 2:{
                queue_put(q2,task_in);
                break;}
            case 3:{
                queue_put(q3,task_in);
                break;}
        }}
        //вывод
        printf("q1: "); queue_print(q1);
        printf("q2: "); queue_print(q2);
        printf("q3: "); queue_print(q3);
        printf("s :  "); stack_print(s);
        printf("p1: ");
        if (p1.status>0){
            task_out(p1.task);
            printf("\n");
        } else printf("idle\n");
        printf("p2: ");
        if (p2.status>0){
            task_out(p2.task);
            printf("\n");
        } else printf("idle\n");

        clock_stop=(p1.status==0)&&(p2.status==0)&&(queue_empty(q1))&&(queue_empty(q2))&&(queue_empty(q3))&&stack_empty(s)&&input_flag;
        tick++;
    }
    return 0;
}
