#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1E-4


void read_matr(double **b, double *c, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            scanf("%lf", &b[i][j]);
        }
        scanf("%lf", &c[i]);
    }
}

void print_matr(double **b, double *c, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%lf ", b[i][j]);
        }
        printf("%lf\n", c[i]);
    }
}

void transform_matr(double **b, double *c, int size){
    double temp = 0;
    for (int k = 0; k < size; k++){
        for (int i = 0; i < size; i++){
            temp = -b[i][i];
            c[i] /= temp;
            for (int j = 0; j <= size; j++){
                b[i][j] /= temp;
            }
        }
    }
    for (int i = 0; i < size; i++){
        c[i] = -c[i];
        for (int j = 0; j < size; j++)
            b[i][i] = 0;
    }
}

double matr_norm(double **a, int size){
    double sum = 0, max = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            sum += fabs(a[i][j]);
        }
        if (sum > max) max = sum;
        sum = 0;
    }
    return max;
}

double accuracy_calc(double **a, int size){
    double norm = matr_norm(a, size);
    return ((1 - norm) / norm)*EPS;
}

double *interation_method(double **b, double *c, int size){
    transform_matr(b, c, size);
    print_matr(b, c, size);
    double *x = (double*)malloc(sizeof(double)*size);
    double *x0 =(double*) malloc(sizeof(double)*size);
    double *E =(double*) malloc(sizeof(double)*size);
    double max = 0, per = 0;
    per = accuracy_calc(b, size);
    printf("%s\n", );
    for (int i = 0; i < size; i++){
        x0[i] = c[i];
    int counter = 0;
    do{
        for (int i = 0; i < size; i++){
            x[i] = 0;
            for (int j = 0; j < size; j++){
                x[i] += b[i][j] * x0[j];
            }
            x[i] += c[i];
            E[i] = fabs(x[i] - x0[i]);
            printf("%f   ",E[i]);
            printf("\n");
        }
        max = 0;
        for (int i = 0; i < size; i++){
            if (max < E[i]) max = E[i];
            printf("max = %f\n",max);
            x0[i] = x[i];
        }
        counter++;
    } while ((max > per)&&(counter!=10));
    printf("Iterations count = %i\n", counter);
    return x;
    free(x0);
    free(E);
}}

double *resudial(double *x, double **B, double *C, int size){
    double *res = malloc(sizeof(double) * size);
    for (int i = 0; i<size; i++){
        res[i] = 0;
        for (int j = 0; j<size; j++){
            res[i] += x[j]*B[i][j];
        }
        res[i] -= C[i];
    }
    return res;
}


int main(){
    int size;
    printf("count of var - \n");
    scanf("%i", &size);
    double **b = malloc(sizeof(double *)*size);
    for (int i = 0; i < size; i++)
        b[i] = malloc(sizeof(double)*size);
    double *c = malloc(sizeof(double)*size);
    read_matr(b, c, size);
    double **prev_b = malloc(sizeof(double *)*size);
    for (int i = 0; i < size; i++){
        prev_b[i] = malloc(sizeof(double)*size);
        for (int j = 0; j<size; j++){
            prev_b[i][j] = b[i][j];
        }
    }
    double *prev_c = malloc(sizeof(double)*size);
    for (int i = 0; i<size; i++){
        prev_c[i] = c[i];
    }
    printf("You entered \n");
    print_matr(b, c, size);

    double *x = interation_method(b, c, size);
    for (int i = 0; i < size; i++){
        printf("x%i = %lf ", i+1, x[i]);
    }
    double *rv = resudial(x, prev_b, prev_c, size);
    for (int i = 0; i<size; i++){
           printf("%lf ", rv[i]);
       }

    return 0;
}
