#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define n 2
#define m 4

void read_arr(int a[][m])
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

void write_arr(int a[][m])
{
    int i,j;
    for (i=0;i<n;i++)
        {   printf("\n");
            for (j=0;j<m;j++)
            printf("%d ",a[i][j]);
        }
}

float geom_avr(int a[][m])
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
            printf("\nR=%d\nC=%d\n",r,c);
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
    int i,j;//N - кол-во строк , M - столбцов
    int a[n][m];
    float r;
    read_arr(a);
    write_arr(a);
    r=geom_avr(a);
    printf("\nGeometry avr = %f",r);
}
