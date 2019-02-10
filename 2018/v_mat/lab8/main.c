#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 0.0001

double f(double x){
    return x*x*x-4*x*x+x+6;
}

double first_der(double x){
    return 3*x*x-8*x+1;
}

double second_der(double x){
    return 6*x-8;
}

double combined_method(double a,double b){
    double t,x0_x,x0_k,x_x,x_k;
        if(second_der(a)*f(a)<0){
            t=a;
            x_x=b;
            x_k=a;
            }
        else{
            t=b;
            x_x=a;
            x_k=b;
        }
        while(fabs(x_k-x_x)<EPS){
            x0_x=x_x;
            x0_k=x_k;
            x_k=x0_k-f(x0_k)/first_der(x0_k);
            x_x=x0_x-f(x0_x)*(t-x0_x)/(f(t)-f(x0_x));
        }
    return (x_k+x_x)/2;
}

int main() {
    printf("x = %f\n",combined_method(2.5,4));
    return 0;
}
