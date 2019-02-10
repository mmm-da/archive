#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 15
#define K 150
typedef int(*t_func)(int**);

void print_matr(int a[N][N]){
    printf("\n");
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
}
void read_matr(int a[N][N]){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            scanf("%i", &a[i][j]);
        }
    }
}
void copy_matr(int a[N][N], int b[N][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            b[i][j]=a[i][j];
        }
    }
}
void get_I(int I[N][N]){
    for (int i=0; i<N; i++){
        I[i][i]=1;
    }
}
int equal(int a[N][N], int b[N][N]){
  int f = 1;
  int x = 1;
  int y;
  while (x<=N && f){
    y=1;
    while(y<=N && f){
      f=(a[x-1][y-1] == b[x-1][y-1]);
      y++;
    }
    x++;
  }
  return f;
}
int inclusion(int a[N][N], int b[N][N]){
  int f = 1;
  int x = 1;
  int y;
  while (x<=N && f){
    y=1;
    while(y<=N && f){
      f=(a[x-1][y-1] <= b[x-1][y-1]);
      y++;
    }
    x++;
  }
  return f;
}
void unite(int a[N][N], int b[N][N], int (*c)[N][N]){
  for (int i = 0; i<N; i++){
    for (int j = 0; j<N; j++){
      (*c)[i][j]=a[i][j] || b[i][j];
    }
  }
}
void composition(int a[N][N], int b[N][N], int (*c)[N][N]){
  for (int i = 0; i<N; i++){
    for (int j = 0; j<N; j++){
      (*c)[i][j]=0;
      for (int z = 0; z<N; z++){
        (*c)[i][j] = (*c)[i][j] || (a[i][z] && b[z][j]);
      }
    }
  }
}
int transit_closure(int a[N][N]){
    int count=1;
    int c_tran[N][N];
    int c2[N][N];
    int tmp[N][N];
    copy_matr(a, c_tran);
    composition(c_tran, c_tran, &c2);
    while(!(inclusion(c2, c_tran))){
        unite(c_tran, c2, &tmp);
        copy_matr(tmp, c_tran);
        composition(c_tran, c_tran, &c2);
        count+=3;
    }
    //printf("1:");
    //print_matr(c2);
    return count;
}
int AOC(int a[N][N]){
    int count=0;
    int c_tran[N][N];
    int a_i[N][N];
    int tmp[N][N];
    copy_matr(a, c_tran);
    copy_matr(a, a_i);
    for(int i=2; i<N; i++){
        composition(a_i, a_i, &tmp);
        copy_matr(tmp, a_i);
        unite(c_tran, a_i, &tmp);
        copy_matr(tmp, c_tran);
        count+=2;
    }
    //printf("AOC:");
    //print_matr(c_tran);
    return count;
}
int AOC_improved(int a[N][N]){
    int count=1;
    int I[N][N];
    int tmp[N][N];
    int tmp1[N][N];
    get_I(I);
    unite(I, a, &tmp);
    for (int i=2; i<N-2; i++){
        composition (tmp, tmp, &tmp1);
        copy_matr(tmp1, tmp);
        count++;
    }
    composition(a, tmp, &tmp1);
    //printf("AOC imp:");
    //print_matr(tmp1);
    return ++count;
}
int AY(int a[N][N]){
    int count=0;
    int c[N][N];
    int tmp[N][N];
    copy_matr(a, c);
    for (int z=0; z<N; z++){
        for (int x=0; x<N; x++){
            for (int y=0; y<N; y++){
                c[x][y]=c[x][y] || c[x][z] && c[z][y];
                count+=2;
            }
        }
    }
    //printf("AY:");
    //print_matr(c);
    return count;
}
int AY_improved (int a[N][N]){
    int count=0;
    int c[N][N];
    int tmp[N][N];
    copy_matr(a, c);
    for (int z=0; z<N; z++){
        for (int x=0; x<N; x++){
            for (int y=0; y<N; y++){
                if(c[x][z]){
                    c[x][y]=c[x][y] || c[z][y];
                    count+=2;
                }
            }
        }
    }
    //printf("AY imp:");
    //print_matr(c);
    return count;
}
void randomize_matr (int a[N][N]){
    int i, j;
    for (int k=0; k<K; k++){
        i=rand()%N;
        j=rand()%N;
        if (a[i][j]){
             k--;
        } else {
            a[i][j]=1;
        }
    }
}
void clean_matr(int a[N][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            a[i][j]=0;
        }
    }
}
void get_rev(int a[N][N], t_func func){
    int max_k=0, min_k=10000000, tmp;
    int min_rev[N][N];
    int max_rev[N][N];
    int tmp_rev[N][N];
    for (int k=0; k<1; k++){
        randomize_matr(a);
        copy_matr(a, tmp_rev);
        tmp=func(tmp_rev);
        if (tmp<min_k){
            min_k=tmp;
            copy_matr(a, min_rev);
        } else {
            if (tmp>max_k){
                max_k=tmp;
                copy_matr(a, max_rev);
            }
        }
        clean_matr(a);
    }
    printf ("%i - max counter\n", max_k);
    //print_matr(max_rev);
    printf ("%i - min counter\n", min_k);
    //print_matr(min_rev);
}
int main(){
    int a[N][N]={};
    printf("transitive closure\n");
    get_rev(a,transit_closure);
    printf("AY\n");
    get_rev(a,AY);
    printf("AY improve\n");
    get_rev(a,AY_improved);
    printf("AOC\n");
    get_rev(a,AOC);
    printf("AOC improve\n");
    get_rev(a,AOC_improved);
}
