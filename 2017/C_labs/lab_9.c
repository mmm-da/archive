#include <stdio.h>

struct std
{
    char Fname[255];
    char Sname[255];
    char Tname[255];
    char num_sch;
    char num_cls;
    char mark1;
    char mark2;
    char mark3;
    char mark4;
    char mark5;

};
struct std read_std()
{
    struct std t;
    printf("\nInput first name - ");
    scanf("%s",&t.Fname);
    printf("\nInput second name - ");
    scanf("%s",&t.Sname);
    printf("\nInput third name - ");
    scanf("%s",&t.Tname);
    printf("\nInput class number - ");
    scanf("\n%d",&t.num_cls);
    printf("\nInput school number - ");
    scanf("\n%d",&t.num_sch);
    printf("\nInput marks - ");
    scanf("\n%d %d %d %d %d",&t.mark1,&t.mark2,&t.mark3,&t.mark4,&t.mark5);
    return t;
}
void main()
{
    int n,i,max=0,t=0,maxlbl=0;
    printf("Input number of students - ");
    scanf("%d",&n);
    struct std lst[n];
    for(i=0;i<n;i++)
    {
        printf("\nReading label ¹%d ",i);
        lst[i]=read_std();
    }
      for(i=0;i<n;i++)
    {
        t=0;
        t=lst[i].mark1+lst[i].mark2+lst[i].mark3+lst[i].mark4+lst[i].mark5;
        if (max<t)
            {
                max=t;
                maxlbl=i;
            }
    }
    printf("Student with best marks - %s %s %s",lst[maxlbl].Fname,lst[maxlbl].Sname,lst[maxlbl].Tname);
}
