#include "graphics.h"

void print_poly(Line * arr,unsigned size){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(7);
    setcolor(0);
    int shift_x=20;
    int shift_y=30;

    point* p_arr=point_arr_init(size);
    Line_to_point_arr(arr,p_arr,size);
    for(int i=0;i<size;i++){
        circle(p_arr[i].x+shift_x,p_arr[i].y+shift_y,4);
    }
    shift_x=250;
    for(int i=0;i<size;i++){
        circle(p_arr[i].x+shift_x,p_arr[i].y+shift_y,4);
        line(arr[i].a.x+shift_x,arr[i].a.y+shift_y,arr[i].b.x+shift_x,arr[i].b.y+shift_y);
    }
    delay(5000000);
    closegraph();
}
