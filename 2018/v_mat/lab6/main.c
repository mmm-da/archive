#include <stdio.h>
#include <stdlib.h>

const double eps = 0.0001;
typedef double(*func)(double x);

double search_method(func f,double a,double b){
    int step_count = (b - a)/eps - 1;
    double x[step_count+2], y[step_count+2], min, x_min;
    x[0] = a;
    for (int i = 1; i <= step_count + 1; i++)
    x[i] = x[i-1] + eps;
    min = f(x[0]); x_min = x[0];
    for (int i = 0; i <= step_count + 1; i++){
        y[i] = f(x[i]);
        if (y[i] < min){
            min = y[i];
            x_min = x[i];
        }
    }
    return x_min;
}


double fibb_method(func f,double a,double b){
    int step_count = 20;//(b - a)/eps - 1;
    double fibb_row[step_count+2], min, a_k = a, b_k = b, a1, b1;
    fibb_row[0] = 1; fibb_row[1] = 1;
    for (int i = 2; i <= step_count + 1; i++)
    fibb_row[i] = fibb_row[i-1] + fibb_row[i-2];
    for (int k = 0; k <= step_count - 2; k++){
        a1 = a_k + fibb_row[step_count-k-1]/fibb_row[step_count-k+1]*(b_k - a_k);
        b1 = a_k + fibb_row[step_count-k]/fibb_row[step_count-k+1]*(b_k - a_k);
        if (f(a1) <= f(b1)) b_k = b1;
        else a_k = a1;
    }
    if (f(a1) <= f(b1)) min = a1;
    else min = b1;
    return min;
}


double div_method(func f,double a,double b){
    int step_count = (b - a)/eps - 1;
    double min, a_k = a, b_k = b, a1, b1;
    for (int k = 0; k <= step_count; k++){
        a1 = (a_k + b_k)/2 - eps;
        b1 = (a_k + b_k)/2 + eps;
        if (f(a1) <= f(b1)) b_k = b1;
        else a_k = a1;
    }
    min = (b_k + a_k)/2;
    return min;
}

double f1(double x){
    return -(x*x+1)*(x*x-4);
}

int main(){
    double min,a=-1.225,b=1.225;
    min=search_method(f1,a,b);
    printf("Optimal search method result x_min = %f f(x) = %f\n",min,f1(min));
    min=fibb_method(f1,a,b);
    printf("Fibonacci search method result x_min = %f f(x) = %f\n",min,f1(min));
    min=div_method(f1,a,b);
    printf("Division method result x_min = %f f(x) = %f\n",min,f1(min));
    return 1;
}
