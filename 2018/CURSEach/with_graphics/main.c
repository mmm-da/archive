#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "polygon_gen.h"
#include <time.h>
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

int main(int argc,char** argv){
    if(argc==1) {
        console_mode();
    }
    else{
    switch (argv[1][1]) {
        case 'h' :
            printf("poly_gen \n  Polygon generator with minimal perimetr\n -h help\n-f input from file");
        break;
        case 'f' :{
            char* name=argv[2];
            FILE *file_in;
            file_in=fopen(name,"r");
            if(file_in!=NULL){
                point* arr;
                unsigned size=read_point_file(file_in,arr);
                fclose(file_in);
                gen_minimal_poly(arr,size);
            }
            else{
                printf("Wrong file name or file don't exist\n");
            }}
        default:
            console_mode();
    }}
    return 1;
}
