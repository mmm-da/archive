#ifndef POINT_H_
#define POINT_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}point;

typedef struct {
    point a;
    point b;
}Line;


point* point_arr_init(unsigned size);
Line* Line_arr_init(unsigned size);
int point_rotate(point a,point b, point c);
double Line_lenght(Line a);
int Line_intersect(Line a, Line b);
point* point_arr_init(unsigned size);
void point_swap(point* a,point* b);
void point_to_Line_arr(point* orig,Line* dest,unsigned size);
void Line_to_point_arr(Line* orig,point* dest,unsigned size);
void point_read_arr(point *arr,int size);
void point_write_arr(point *arr,int size);
void print_Line(Line a);
void print_point(point a);
void Line_write_arr(Line* arr,int size);
int point_to_Line_lenght(Line a, point b);
void Line_arr_delete(Line* arr,int size);
#endif
