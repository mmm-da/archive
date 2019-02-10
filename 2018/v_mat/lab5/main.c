#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double (*func)(double, double);

double f(double x,double y){
    return 1.5-sin(x-1)-y;
}

double df_dx(double x,double y){
    return -cos(x-1);
}

double df_dy(double x,double y){
    return -1;
}

double F(double x,double y){
    return 0.8+sin(x+1)-y;
}

double dF_dx(double x,double y){
    return cos(x+1);
}

double dF_dy(double x,double y){
    return -1;
}


int method_newton(func f,func F,func df_dx,func df_dy,func dF_dx,func dF_dy,double eps,unsigned count,double x_0,double y_0,double *r_x,double *r_y){
    int i=0;
    double x_1,y_1,det,det1,det2,h,l;
    while(i<=count){
        double k[2][3]={{df_dx(x_0, y_0),df_dy(x_0, y_0),-f(x_0, y_0)},
                        {dF_dx(x_0, y_0),dF_dy(x_0, y_0),-F(x_0, y_0)}
                       };
        det = k[0][0] * k[1][1] - k[0][1] * k[1][0];
        if (det == 0) return 0;
        det1 = k[0][2] * k[1][1] - k[0][1] * k[1][2];
        det2 = k[0][0] * k[1][2] - k[0][2] * k[1][0];
        h = det1/det;
        l = det2/det;
        x_1 = x_0+h;
        y_1 = y_0+l;
        if (fabs(f(x_1, y_1))+fabs(F(x_1, y_1)) < eps){
            *r_x = x_1;
            *r_y = y_0;
            return 1;
        }
        x_0 = x_1;
        y_0 = y_1;
        i++;
    }
    printf("%f\n",(fabs(f(x_1, y_1))+fabs(F(x_1, y_1))));
    return 0;
}

int main(){
    double x_0,y_0,x,y;
    x_0=1.0;
    y_0=2.0;
    printf("x_0 = %f\ny_0 = %f\n",x_0,y_0);
    if(method_newton(f,F,df_dx,df_dy,dF_dx,dF_dy,0.001,200,x_0,y_0,&x,&y)){
        printf("result - %f %f\n",x,y);
    }
    else{
        printf("\ncant solve this\n");
    }
    return 0;
}
