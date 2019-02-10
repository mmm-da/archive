`#include <stdio.h>
#include <math.h>

int size_of_num(int num)
{
    int i=1,k=1;
    while (num>k)
    {
        i++;
        k*=2;
    }
    return i;
}
int revers_Bnum(int num,int size)
{
    int t,i,mask=pow(2,size-1);
    for(i=1;i==size-1;i++)
    {
        t=num&1;
        num=num>>1;
        if (t=1)
            {
            num=num|mask;
            }
    }
}


int main()
{
  int a;
  scanf("Input number - %d",&a);
  revers_Bnum(a,size_of_num(a));
  printf("%d",a);
}

