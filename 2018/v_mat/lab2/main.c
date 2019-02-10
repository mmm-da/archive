#include <stdio.h>
#include <stdlib.h>

int fact(int a){
  return a==0 ? 1 : fact(a-1)*a;
}

float** init_Table(int size){
  float **a = (float **)malloc(size*sizeof(float *));
  a[0] = (float *)malloc(size*sizeof(float));
  a[1] = (float *)malloc(size*sizeof(float));
  for (int i=2; i<=size; i++){
    a[i] = (float *)malloc((size-(i-1))*sizeof(float));
  }
  return a;
}

float ev_interTable(float a,float **table,int size,int step){
  float r,t,mult;
  int i,j;
  for(i=1;i<size;i++){
      for(j=0;j<size-i;j++){
          table[j][i+1]=table[j+1][i]-table[j][i];
          }
  }
  if(!(a>table[(size-1)/2][0])){
    t=((a-table[0][0])/(float)step);
    mult=t;
    a=table[0][1];
    for(i=1;i<size;i++){
        a+=(table[0][i+1]*mult)/fact(i);
        mult*=(t-i);
    }
  }
  else{
    t=(a/(float)step)-(table[size-1][0]/(float)step);
    mult=t;
    r=table[size-1][1];
    for(i=size-1;i>0;i--){
        r+=(table[0][i+1]*mult)/fact(i);
        mult*=(t+i);}}
  return r;
};

double unev_interTable(float a, float **table, int size){
  float r,t,mult;
  int i,j;
  for(i=1;i<size;i++){
      for(j=0;j<size-i;j++){
          table[j][i+1]=(table[j+1][i]-table[j][i])/(table[j+i][0]-table[j][0]);}
  }
  r=table[0][1];
  mult=(a-table[0][0]);
  for(i=1;i<size;i++){
    r+=mult*table[0][i+1];
    mult*=(a-table[i][0]);}
  return r;
};

int main(){
  float a,**table,r;
  int step,size,i,j;
  char flag;
  printf("Input a - ");
  scanf("%f",&a);
  printf("Input size of table - ");
  scanf("%i",&size);
  table=init_Table(size);
  printf("\nInput table \nx y\n");
  scanf("%f ",&table[0][0]);
  scanf("%f",&table[0][1]);
  scanf("%f ",&table[1][0]);
  scanf("%f",&table[1][1]);
  step=table[1]-table[0];
  for(i=2;i<size;i++){
      scanf("%f ",&table[i][0]);
      scanf("%f",&table[i][1]);
      if(table[i]-table[i-1]!=step) flag=0;
  }
  if(flag) r=ev_interTable(a,table,size,step);
  else r=unev_interTable(a,table,size);
  printf("\nResult = %f",r);
  return 0;
}
