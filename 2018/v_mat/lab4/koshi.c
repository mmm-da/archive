#include "koshi.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double **method_euler(func f, double a, double b, double y0,int* count){
    double x = a;
    double y = y0;
    double h = (b-a)/(*count);
    double **result = malloc_array(*count);
    result[0][0] = x;
    result[0][1] = y;
    for (int i = 0; i < *count; i++){
        y = y+h*f(x, y);
        x+=h;
        result[i+1][0] = x;
        result[i+1][1] = y;
    }
    return result;
}

double **method_euler_cauchy(func f, double a, double b, double y0,int* count){
    double x = a;
    double y = y0;
    double h = (b-a)/(*count);
    double **result = malloc_array(*count);
    result[0][0] = x;
    result[0][1] = y;
    for (unsigned k = 0; k < *count; k++){
        y = y+h/2*(f(x, y)+f(x+h, y+h*f(x,y)));
        x+=h;
        result[k+1][0] = x;
        result[k+1][1] = y;
    }
    return result;
}

double **method_mod_euler(func f, double a, double b, double y0,int* count){
    double x = a;
    double y = y0;
    double h = (b-a)/(*count);
    double **result = malloc_array(*count);
    result[0][0] = x;
    result[0][1] = y;
    for (unsigned k = 0; k < *count; k++){
        y = y+h*f(x+h/2, y+h/2*f(x,y));
        result[k+1][0] = x;
        result[k+1][1] = y;
        x+=h;
    }
    return result;
}

double **method_runge_kutta(func f, double a, double b, double y0,int* count){
    double x = a;
    double y = y0;
    double h = (b-a)/(*count);
    double m1, m2, m3, m4;
    double **result = malloc_array(*count);
    result[0][0] = x;
    result[0][1] = y;
    for (unsigned k = 0; k < *count; k++){
        m1 = f(x, y);
        m2 = f(x+h/2, y+h*m1/2);
        m3 = f(x+h/2, y+h*m2/2);
        m4 = f(x+h, y+h*m3);
        y = y+h/6*(m1+2*m2+2*m3+m4);
        x+=h;
        result[k+1][0] = x;
        result[k+1][1] = y;
    }
    return result;
}

void free_array(double **a, unsigned n){
    for (unsigned i = 0; i<n; i++){
        free(a[i]);
    }
    free(a);
}

double** malloc_array(unsigned n){
    double **result = (double **)malloc(sizeof(double *)*(n+1));
    for (int i = 0; i<=n; i++){
        result[i] = (double *)malloc(sizeof(double)*2);
    }
    return result;
}

double **runge_eps(method_func method,func fx, double a, double b, double y0,double eps,int *count,int acc_order){
    double **result1, **result2;
    double delta;
    result1 = method(fx,a,b,y0,count);
    (*count)*=2;
    result2 = method(fx,a,b,y0,count);
    delta = fabs(result2[*count][1]-result1[*count/2][1])/((1<<acc_order)-1);
    while (delta > eps){
      free_array(result1, *count/2+1);
      result1=result2;
      (*count)*=2;
      result2 = method(fx,a,b,y0,count);
      delta = abs(result2[*count][1]-result1[*count/2][1])/((1<<acc_order)-1);
    }
    free_array(result1, *count/2+1);
    return result2;
}
