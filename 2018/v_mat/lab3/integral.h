#ifndef INTEGRAL_H_
#define  INTEGRAL_H_

double (*integral_func) (double);

double integral_rect(double (*func) (double),double a,double b,int n,double eps);
double integral_tr(double (*func) (double),double a,double b,int n,double eps);
double integral_pb(double (*func) (double),double a,double b,int n,double eps);
double integral_gause(double (*func) (double),double a,double b,int n);
#endif
