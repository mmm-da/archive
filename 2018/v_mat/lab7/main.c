#include <stdio.h>
#include <math.h>
typedef double (*func)(double, double);
typedef struct {
    func der_x1;
    func der_x2;
}grad;
typedef struct {
    double x1;
    double x2;
}point;
double f(double x1, double x2){
    return 2*x1*x1-3*x1+2*x2*x2-8*x2+2;
}
double der_x1(double x1, double x2){
    return 4*x1-3;
}
double der_x2(double x1, double x2){
    return 4*x2-8;
}
int solve(func f, grad g, point M0, double epsilon, int max_iterations,
double alpha, double beta, double gamma, point *minimum, double *min_val){
    point M1;
    double f_M0, f_M1;
    int k = 0;
    double x_1, x_2, r, t;
    while (k<=max_iterations){
        f_M0 = f(M0.x1, M0.x2);
        int i = 0;
        do{
            x_1 = M0.x1-alpha*pow(gamma, i)*g.der_x1(M0.x1, M0.x2);
            x_2 = M0.x2-alpha*pow(gamma, i)*g.der_x2(M0.x1, M0.x2);
            r = f(x_1, x_2) - f_M0;
            x_1 = g.der_x1(M0.x1, M0.x2);
            x_2 = g.der_x2(M0.x1, M0.x2);
            t = pow(x_1, 2) + pow(x_2, 2);
            t = -beta*alpha*pow(gamma, i)*t;
            i++;
        }while (!(r<t));
        i = i-1;
        M1.x1 = M0.x1-alpha*pow(gamma, i)*g.der_x1(M0.x1, M0.x2);
        M1.x2 = M0.x2-alpha*pow(gamma, i)*g.der_x2(M0.x1, M0.x2);
        f_M1 = f(M1.x1, M1.x2);
        printf("iter - %d point %f,%f\n",k, M1.x1, M1.x2);
        if (fabs(f_M0-f_M1)<epsilon){
            minimum->x1 = M1.x1;
            minimum->x2 = M1.x2;
            *min_val = f_M1;
            return 1;
        }
        M0.x1 = M1.x1;
        M0.x2 = M1.x2;
        k++;
    }
    return 0;
}
int main(){
    const grad g = {der_x1, der_x2};
    const point M0 = {0,0};
    const double epsilon = 0.01;
    const int n = 500;
    const double alpha = 1, beta = 0.5, gamma = 0.5;
    point p_min;
    double f_min;
    if (solve(f, g, M0, epsilon, n, alpha, beta, gamma, &p_min, &f_min)){
        printf("point %f,%f", p_min.x1, p_min.x2);
    }else{
        printf("can't resolve");
    }
    return 0;
}
