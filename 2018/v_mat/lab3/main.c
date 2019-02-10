#include <stdlib.h>
#include <stdio.h>
#include "integral.h"
#include <math.h>

double func_1 (double x){
    return (x*x*x*x*x)+1;
}
double func_2 (double x){
    return 2*sin(x)+cos(x);
}
double func_3 (double x){
    return exp(2*x);
}
 int main(){
     double result;
     integral_func=func_1;

     printf("\nRectangular method R=");
     result=integral_rect(integral_func,0,4,4,0.000001);
     printf("%f\n",result);

     printf("\nTrapetion method R=");
     result=integral_tr(integral_func,0,4,4,0.000001);
     printf("%f\n",result);

     printf("\nParabolic method R=");
     result=integral_pb(integral_func,0,4,4,0.000001);
     printf("%f\n",result);

     printf("\nGause method R=" );
     result=integral_gause(integral_func,0,4,3);
     printf("%f\n",result);
     return 0;
 }
