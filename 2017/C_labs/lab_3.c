#include <stdio.h>
#include <math.h>
#define BIT_SIZE sizeof(int)*8
#define MASK_1 1 << (BIT_SIZE - 1)

int revers_Bint(int num, int k)
{
    int r=0;
    int sft=0;
    int t=k;
    printf("\nCalculating count of shift\n");
    while (t!=1)
    {
        sft+=1;
        t=t/2;
    }
    printf("\nShift count - %d\n",sft);
    while(num!=0)
    {
        //printf("\nIteration of while num=%d r=%d",num,r);
        t=num&k-1;
        r=r<<sft|t;
        num=num>>sft;
    }
    return r;
}

void printb(int x)
{
for (int i = 1; i<=BIT_SIZE; i++)
{
printf("%d", (x & MASK_1) >> (BIT_SIZE - 1));
x=x<<1;
}
}

int main()
{
    int num,k;
    float Fnum;
    printf("Input  int number - ");
    scanf("%d",&num);
    printb(num);
    printf("\nInput k - ");
    scanf("%d",&k);
    num=revers_Bint(num,k);
    printb(num);
    printf("\n%d",num);



}
