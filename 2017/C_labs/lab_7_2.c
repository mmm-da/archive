// N - константа M исходные данные


#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define n 2

void read_arr(int *a[n],int m)
{
    int i,j;
    printf("\nN=%d\nM=%d\n",n,m);
    for (i=0;i<n;i++)
    {
        a[i]=(int*)malloc(m*sizeof(int));
        for (j=0;j<m;j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d",&a[i][j]);
        }
    }
    return a;
}

void write_arr(int* a[n],int m)
{
    int i,j;
    for (i=0;i<n;i++)
        {   printf("\n");
            for (j=0;j<m;j++)
            printf("%d ",a[i][j]);
        }
}

float geom_avr(int *a[n],int m)
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

int main()
{

    int m,i,j;//N - кол-во строк , M - столбцов
    int *a[n];
    float r;
    printf("Input M - ");
    scanf("%d",&m);
    read_arr(a,m);
    write_arr(a,m);
    r=geom_avr(a,m);
    printf("\nGeometry avr = %f",r);
}
