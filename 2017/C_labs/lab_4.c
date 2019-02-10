
#include <stdio.h>
#include <math.h>

float read_chrFnum()
{
    char c=0,i=1;
    int d=0;
    float num=0,temp=1e-1,t = 1e-1;
    printf("\nInput your num - ");
    while ((c!='.')&&(c!=','))
    {
        scanf("%c",&c);
        if (c=='-')
        {
            i=-1;
        }
        if ((c>='0')&&(c<='9'))
        {
            num*=10;
            num=num+(c-'0');
        }
    }
    c=0;
    while (c!='\n')
    {
        scanf("%c",&c);
        if (c!='\n')
        {
            num=num+((c-'0')*t);
            t=t*temp;
        }
    }
    num*=i;
    fflush(stdin);
    return num;
}

int main()
{
    int i,n,t;
    float num,max;
    printf("Input count of nums - ");
    scanf("\n%d",&n);
    num=read_chrFnum();
    max=num;
    for(i=1;i<n;i++)
    {
    num=read_chrFnum();
    if (max<num)
    {
        max=num;

    }
    }
    printf("\nMax num is %f",max);
}
