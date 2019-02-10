#include "file.h"
unsigned read_point_file(FILE* file_in, point* arr_out){
    int size=10;
    int i=0;
    arr_out=point_arr_init(size);
    char current_char;
    while((fscanf(file_in,"%d:%d",&arr_out[i].x,&arr_out[size].y))!=EOF){
        i++;
        if(size<=i){
            size*=2;
            arr_out=(point*)realloc(arr_out,size);
        }
    }
    arr_out=(point*)realloc(arr_out,i);
    return size;
}

void write_point_file(point* arr_in,unsigned size){
    FILE* file_out=fopen("./result.txt","w");
    for (int i=0;i<size;i++){
        printf("i=%d\n",i);
        print_point(arr_in[i]);
        fprintf(file_out,"%d:%d ",arr_in[i].x,arr_in[i].y);
      }
    fclose(file_out);
}
