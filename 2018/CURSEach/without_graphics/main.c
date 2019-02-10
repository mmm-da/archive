#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "polygon_gen.h"
#include <time.h>
#include <string.h>

int count=0;
void console_mode(){
    printf("Write count of points - ");
    int size;
    scanf("%d",&size);
    point* arr=point_arr_init(size);
    point_read_arr(arr,size);
    clock_t start = clock();
    gen_minimal_poly(arr,size);
    clock_t end = clock();
    printf("Count of intersect check - %d\n",count);
    printf("Runtime - %f sec\n",(double)(end-start)/CLOCKS_PER_SEC );
    free(arr);
}

void file_mode(char* name){
    FILE *file_in;
    file_in=fopen(name,"r");
    if(file_in!=NULL){
        unsigned size;
        point* arr=read_point_file(file_in,&size);
        point_write_arr(arr,size);
        fclose(file_in);
        gen_minimal_poly(arr,size);
    }
    else{
        printf("Wrong file name or file don't exist\n");
    }
}

int main(){
    char str_name[50];
    printf("Input file path: ");
    scanf("%s",str_name);
    if(strcmp(str_name,"console")!=0){
        file_mode(str_name);
    }
    else{
        console_mode();
    }
}
