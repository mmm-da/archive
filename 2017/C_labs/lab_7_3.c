#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define m 4
typedef int (*t_matr)[m];
int** read_arr(t_matr a,int n)
{
    int i,j;
    printf("\nN=%d\nM=%d\n",n,m);
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d",&a[i][j]);
        }
    }
    return a;
}

void write_arr(t_matr a,int n)
{
    int i,j;
    for (i=0;i<n;i++)
        {   printf("\n");
            for (j=0;j<m;j++)
            printf("%d ",a[i][j]);
        }
}

float geom_avr(t_matr a,int n)
{
    int i,j,r=1,c=0;
    float t;
    printf("\nStart calc avr\n");
    for(i=0;i<n;i++)
    {
        for(j=n-i-1;j<m-i;j++)
        {
            printf("a[%d][%d]\n", i, j);
            r*=a[i][j];
            printf("R=%d\nC=%d",r,c);
            c++;
        }
    }
    t=1.0/c;
    printf("T=%f",t);
    r=pow(r,t);
    return r;

}

void mem_aloc(t_matr *a, int n){
    *a = (t_matr)malloc(m*n*sizeof(int*));
}

int main()
{

    int n,i,j;//N - кол-во строк , M - столбцов
    t_matr a;
    float r;
    printf("Input N - ");
    scanf("%d",&n);
    mem_aloc(&a,n);
    a=read_arr(a,n);
    write_arr(a,n);
    r=geom_avr(a,n);
    printf("\nGeometry avr = %f",r);
    free(a);
}
