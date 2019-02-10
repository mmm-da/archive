#include "integral.h"
#include <stdlib.h>
#include <stdio.h>

double integral_rect(double (*func) (double),double a,double b,int n,double eps){
    double o = 1.0/3.0;
    double result,prev_result,result_sub,sum=0,x;
    int count = n;
    double step=(b-a)/(float)count;
    for(int i=0;i<count;i++){
        x=a+(i+0.5)*step;
        sum+=func(x);
    }
    prev_result=sum*step;
    result_sub=1;
    while(result_sub>=eps){
        count*=2;
        step=(b-a)/(float)count;
        sum=0;
        for(int i=0;i<count;i++){
            x=a+(i+0.5)*step;
            sum+=func(x);
        }
        result=step*sum;
        result_sub=o*abs(result-prev_result);
        prev_result=result;
    }
    return result;
}

double integral_tr(double (*func) (double),double a,double b,int n,double eps){
    double o = 1.0/3.0;
    double result,prev_result,result_sub,sum=0,x;
    int count = n;
    double step=(b-a)/(float)count;
    for(int i=0;i<count;i++){
        x=a+i*step;
        sum+=func(x);
    }
    prev_result=step*(((func(a)+func(b))/2.0)+sum);
    result_sub=1;
    while(result_sub>=eps){
        count*=2;
        step=(b-a)/(float)count;
        sum=0;
        for(int i=1;i<count;i++){
            x=a+i*step;
            sum+=func(x);
        }
        result=step*(((func(a)+func(b))/2.0)+sum);
        result_sub=o*abs(result-prev_result);
        prev_result=result;
    }
    return result;

}
double integral_pb(double (*func) (double),double a,double b,int n,double eps){
    double o = 1.0/15.0;
    double result,prev_result,result_sub,sum_1=0,sum_2=0,x;
    int count = n;
    double step=(b-a)/(float)count;
    //цикл для суммы нечетных
    for(int i=1;i<(count-1);i=i+2){
        x=a+i*step;
        sum_1+=func(x);
    }
    //цикл для суммы четных
    for(int i=2;i<(count-2);i=i+2){
        x=a+i*step;
        sum_2+=func(x);
    }
    prev_result=step/3.0*(func(a)+func(b)+4*sum_1+2*sum_2);
    result_sub=1;
    while(result_sub>=eps){
        count*=2;
        step=(b-a)/(float)count;
        sum_1=0;
        sum_2=0;
        //цикл для суммы нечетных
        for(int i=1;i<(count-1);i=i+2){
            x=a+i*step;
            sum_1+=func(x);
        }
        //цикл для суммы четных
        for(int i=2;i<(count-2);i=i+2){
            x=a+i*step;
            sum_2+=func(x);
        }
        result=step/3.0*(func(a)+func(b)+4*sum_1+2*sum_2);
        result_sub=o*abs(result-prev_result);
        prev_result=result;
    }
    return result;

}

double integral_gause(double (*func) (double),double a,double b,int n){

    double gause_scale[4][4]={
        {2.0,0.0,0.0,0.0},
        {1.0,1.0,0.0,0.0},
        {0.5555555556,0.8888888888,0.5555555556,0.0},
        {0.3478548451,0.6521451549,0.6521451549,0.3478548451}
    };

    double gause_node[4][4]={
        {0.0,0.0,0.0,0.0},
        {-0.5773502692,0.5773502692,0.0,0.0},
        {-0.7745966692,0.0,0.7745966692,0.0},
        {-0.8611363115,-0.3399810436,0.3399810436,0.8611363115}
    };

    double result,step,sum=0;
    step=(b-a)/(float)n;
    result=(b-a)/2.0;
    for(int i=0;i<n;i++){
        sum+=gause_scale[n-1][i]*func((b+a)/2.0+((b-a)/2.0)*gause_node[n-1][i]);
    }
    result*=sum;
    return result;
}
