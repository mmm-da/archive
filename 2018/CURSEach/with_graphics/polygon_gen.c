#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "polygon_gen.h"
#include "file.h"
char poly_check_intersect(Line* arr,unsigned size){
    int i,j,f;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if((j!=i-1)&&(j!=i)&&(j!=i+1)){
                if(Line_intersect(arr[i],arr[j])){
                    count+=i*j;
                    return 1;
                }
            }
        }
    }
    count+=size*size;
    return 0;
}

int gen_transposition(unsigned* index_arr,unsigned size){
    int j = size - 2;
    while ((j!= -1) && (index_arr[j] >= index_arr[j+1]))
        j--;
    if (j == -1) return 0;
    int k = size - 1;
    while (index_arr[j] >= index_arr[k]) k--;
    swap(index_arr,j,k);
    int l = j + 1, r = size - 1;
    while (l<r) swap(index_arr,l++,r--);
    return 1;
}

void swap(int *a, int i, int j){
  int s = a[i];
  a[i] = a[j];
  a[j] = s;
}

void gen_poly(int* index_arr,point* point_arr,Line* poly,unsigned size){
    point* temp=point_arr_init(size);
    for(int i=0;i<size;i++){
        temp[i]=point_arr[index_arr[i]-1];
    }
    point_to_Line_arr(temp,poly,size);
    free(temp);
}

double perimetr_poly(Line* arr,unsigned size){
    double sum=0;
    for(int i=0;i<size;i++){
        sum+=Line_lenght(arr[i]);
    }
    return sum;
}

unsigned* gen_index_arr(unsigned size){
    unsigned* arr=(unsigned*)malloc(sizeof(unsigned)*size);
    for(int i=0;i<size;i++){
        arr[i]=i+1;
    }
    return arr;
}

Line* min_perimetr_poly(point* arr,unsigned size){
    unsigned* index_arr=gen_index_arr(size);
    Line* poly_result=Line_arr_init(size);
    Line* poly_current=Line_arr_init(size);
    double min=DBL_MAX;
    double temp;
    char flag=0;
    gen_poly(index_arr,arr,poly_current,size);
    if(!(poly_check_intersect(poly_current,size))){
        temp=perimetr_poly(poly_current,size);
        if(temp<min){
            flag=1;
            min=temp;
            Line_arr_copy(poly_current,poly_result,size);
        }
    }
    while(gen_transposition(index_arr,size)){
        gen_poly(index_arr,arr,poly_current,size);
        if(!(poly_check_intersect(poly_current,size))){
            temp=perimetr_poly(poly_current,size);
            if(temp<min){
                flag=1;
                min=temp;
                Line_arr_copy(poly_current,poly_result,size);
            }
        }
    }
    free(index_arr);
    free(poly_current);
    if (flag){
    return poly_result;
    }
    else return 0;
}


void Line_arr_copy(Line* orig,Line* dest,unsigned size){
    int i;
    for(i=0;i<size;i++){
        dest[i]=orig[i];
    }
}

void gen_minimal_poly(point* arr, unsigned size){

    Line* l_arr = Line_arr_init(size);
    if((l_arr=min_perimetr_poly(arr,size))!=NULL){
        Line_to_point_arr(l_arr,arr,size);
        printf("Result polygon with min perimetr\n");
        point_write_arr(arr,size);
        printf("Perimetr = %f\n",perimetr_poly(l_arr,size));
    }
    else(printf("Can't build polygon"));
    fflush(stdin);
    printf("Save result in file? (y/N) ");
    char m=0;
    scanf("%c",&m);
    if((m=='y')||(m=='Y')){
        printf("flag %c Write result to file\n",m);
        write_point_file(l_arr,size);
    }
    printf("Print polygon on screen? (y/N) ");
    m=0;
    fflush(stdin);
    scanf("%c",&m);
    if((m=='y')||(m=='Y')){
        print_poly(l_arr,size);
    }

}
