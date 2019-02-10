#include "file.h"
point* read_point_file(FILE* file_in,int* size){
    *size=20;
    int i=0;
    point* arr_out=point_arr_init(*size);
    char current_char;
    char* str;
    while((fscanf(file_in,"%d:%d",&arr_out[i].x,&arr_out[i].y))!=EOF){
        i++;
    }
    *size=i;
    return arr_out;
}

void write_point_file(point* arr_in,unsigned size){
    FILE* file_out=fopen("./result.txt","w");
    int i=0;
    while(i<size){
        fprintf(file_out,"%d",arr_in[i].x);
        fprintf(file_out,":");
        fprintf(file_out,"%d ",arr_in[i].y);
        i++;
    }
    fclose(file_out);
}
