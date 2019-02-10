#include <stdio.h>
#include <stdlib.h>

#define N 4

int rel_A(int x,int y)
{
    return (((x+y)%3)==0);
}

int rel_B(int x,int y)
{
    return (((2<x)&&(x<8))&&((2<y)&&(y<8)));
}

int rel_C(int x,int y)
{
    return ((x*x+y*y)<100);
}

void build_rel_matr(int matr[N][N], int func(int, int),int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            matr[i][j] = func(i+1, j+1);
        }
    }
}

void write_matr(int matr[N][N],int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            printf("%i", matr[i][j]);
        }
        printf("\n");
    }
}

int rel_equal(int a[N][N],int b[N][N],int n)
{
    int f=1;
    int x=0;
    int y;
    while(x<=n && f)
    {
        y=0;
        while(y<=n && f)
        {
            f=(a[x][y]==b[x][y]);
            y++;
        }
        x++;
    }
    return f;
}

int rel_inclusion(int a[N][N],int b[N][N],int n)
{
    int f=1;
    int x=0;
    int y;
    while(x<=n && f)
    {
        y=0;
        while(y<=n && f)
        {
            f=(a[x][y]<=b[x][y]);
            y++;
        }
        x++;
    }
    return f;
}


void rel_union(int a[N][N],int b[N][N],int c[N][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j] || b[i][j];
        }
    }
}


void rel_intersect(int a[N][N],int b[N][N],int c[N][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j] && b[i][j];
        }
    }
}

void rel_substraction(int a[N][N],int b[N][N],int c[N][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j] > b[i][j];
        }
    }
}

void rel_sumetric_substraction(int a[N][N],int b[N][N],int c[N][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j] ^ b[i][j];
        }
    }
}

void rel_complited(int a[N][N],int c[N][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=!a[i][j];
        }
    }
}

void rel_exp(int a[N][N],int c[N][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=a[i][j];
        }
    }
}

void rel_composition(int a[N][N], int b[N][N], int c[N][N],int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            c[i][j]=0;
            for (int z = 0; z<n; z++)
            {
                c[i][j] = c[i][j] || (a[i][z] && b[z][j]);
            }
        }
    }
}

void rel_check_reflexive_antireflexive(int a[N][N],int n)
{
    int f,k;
    if(rel_check_reflexive(a,n)!=rel_check_antireflexive(a,n))
    {
        printf("\nThe attitude is not reflexive and not anti-reflective.\n");
    }
    else
    {
        if(rel_check_reflexive(a,n)==1 && rel_check_antireflexive(a,n)==1)
            printf("\nReflexive attitude\n");
        else
            printf("\nAnti-reflexive attitude\n");
    }
}

int rel_check_reflexive(int a[N][N],int n)
{
    int k=1;
    for(int i=0;i<n&&k==1;i++)
    {
        if(a[i][i]==1)
            k=1;
        else
            k=0;
    }
    return k;
}

int rel_check_antireflexive(int a[N][N],int n)
{
    int k=0;
    for(int i=0;i<n&&k==0;i++)
    {
        if(a[i][i]==0)
            k=0;
        else
            k=1;
    }
    return k;
}

int rel_check_symmetrical(int a[N][N],int n)
{
    int i,j;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        if(a[i][j]!=a[j][i])
        return 0;
    return 1;
}

int rel_check_antisymmetrical(int a[N][N],int n)
{
    int i,j;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        if(a[i][j]*a[j][i])
        return 0;
    return 1;
}

int rel_check_transitively(int a[N][N],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(k=0;k<n;k++)
            if(a[i][k])
                for(j=0;j<n;j++)
                    if(a[k][j]==1&&a[i][j]==0)
                    return 0;
    return 1;
}

int rel_check_antitransitively(int a[N][N],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(k=0;k<n;k++)
            if(a[i][k])
                for(j=0;j<n;j++)
                    if(a[k][j]&&a[i][j])
                    return 0;
    return 1;
}

int rel_check_full(int a[N][N],int n)
{
    int i,j;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        if(!(a[i][j]||a[j][i]))
        return 0;
    return 1;
}

int rel_check_tolerance(int a[N][N],int n)
{
    int f,g;
    f=rel_check_reflexive(a,n);
    g=rel_check_symmetrical(a,n);
    return(f*g);
}

int rel_check_equivalence(int a[N][N],int n)
{
    int f,g,l;
    f=rel_check_reflexive(a,n);
    g=rel_check_symmetrical(a,n);
    l=rel_check_transitively(a,n);
    return(f*g*l);
}

int rel_check_order(int a[N][N],int n)
{
    int f,g;
    f=rel_check_antisymmetrical(a,n);
    g=rel_check_transitively(a,n);
    return(f*g);
}

int rel_check_characteristic(int a[N][N],int n)
{
    rel_check_reflexive_antireflexive(a,n);
    int f,c;
    f=rel_check_symmetrical(a,n);
    c=rel_check_antisymmetrical(a,n);
    if(f==1)
        printf("symmetrical\n");
        if(c==1)
            printf("antisymmetrical\n");
        else
            printf("The relationship is neither symmetric nor antisymmetric.\n");
    f=rel_check_transitively(a,n);
    c=rel_check_antitransitively(a,n);
    if(f==1)
        printf("transitively\n");
        if(c==1)
            printf("antitransitively\n");
        else
            printf("Attitude is not transitive and not anti-transitive.\n");
    f=rel_check_full(a,n);
    if(f==1)
        printf("The attitude is complete.");
    else
        printf("The relationship is not complete.");
    f=rel_check_tolerance(a,n);
    if(f==1)
        printf("Relationship is tolerant.");
    f=rel_check_equivalence(a,n);
    if(f==1)
        printf("The ratio is equivalent to.");
    f=rel_check_order(a,n);
    if(f==1)
        printf("Order relationship.");
}
int main(){
    int a[N][N] = {{0,0,0,0},{1,0,0,0},{1,1,0,0},{1,1,1,0}};
    int b[N][N] = {{0,1,1,1},{0,0,1,1},{0,0,0,1},{0,0,0,0}};
    int n=N;
    printf("WRITE MATRIX A\n");
    write_matr(a,n);
    rel_composition(a,a,a,n);
    write_matr(a,n);
    rel_check_characteristic(a,n);
    printf("WRITE MATRIX B\n");
    write_matr(b,n);
    rel_check_characteristic(b,n);
    rel_composition(b,b,b,n);
    write_matr(b,n);

    return 0;
}
