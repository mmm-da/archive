#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void swap(int *a,int *b){
  int t;
  t=*b;
  *b=*a;
  *a=t;
}
void SelSort(int *A,int nn){
  for (int i = 0; i < nn - 1; i++) {
      int min = i;
      for (int j = i + 1; j < nn; j++) {
          if (A[j] < A[min]) {
              min = j;}}
      if (A[min] != A[i]) {
          swap(&A[i],&A[min]);
          min = i;}
  }}
void BSort(int* A,int nn)
{ int i,j,k,r;
  for ( i=0; i<nn-1; i++ ){
    r = 0;
    for (j=nn-1; j>i; j--)
     if (A[j] <A[j-1]){
       swap(&A[j-1],&A[j]);
       r=1;
       }
	 if ( r == 0)
  break;}
}

void InsSort(int *A,int nn)
{ int i,j,k;
for ( j=1; j<nn; j++ )
{  k = A[j];
  i = j -1;
 while ( k < A[i] && i >= 0){
    A[i+1] = A[i];
    i -= 1;
    }
 A[i+1] = k;
}
}
void ShellSort(int *mass,int n)
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}
void QSort(int *a, int L, int R){
  int x = a[(L+R)/2], i = L, j = R, t;
  while (i<=j){
    while (a[i]<x)
	  i++;
	while (a[j]>x)
      j--;
    if (i<=j){
	  swap(&a[i],&a[j]);
    i++;
	  j--;
    }}
  if (L<j)
    QSort(a,L,j);
  if (i<R)
    QSort(a,i,R);
}

void HoarSort(int *a,int n){
  QSort(a,0,n);
}
void Sift(int *array, int left, int right){
  int i = left;
  int j = 2*left+1;
  int x = array[left];
  if (j<right && array[j]<array[j+1]) j++;
  while (j<=right && x<array[j]){
    swap(&array[i], &array[j]);
    i = j;
    j = 2*j+1;
    if (j<right && array[j]<array[j+1]) j++;
  }
}
void HeapSort(int *array, unsigned n){
  int left = n/2 ;
  int right = n-1;
  while(left>0){
    left = left - 1;
    Sift(array, left, right);
  }
  while(right>0){\
    swap(&array[0], &array[right]);
    right--;
    Sift(array, left, right);
  }
}
void ba1Sort(int *array, unsigned n){
  int i = 1;
  int flag = 0;
  do {
    for (int j = n-1; j>=i; j--){
      if (array[j-1] >= array[j]){
        swap(&array[j-1], &array[j]);
        flag = 1;
      }
    }
    i++;
  } while(flag && i<n);
}
void ba2Sort(int *array, unsigned n){
  unsigned i = 0;
  do {
    unsigned last_swapped = n;
    for (int j = n-1; j>i; j--){
      if (array[j-1] >= array[j]){
        swap(&array[j-1], &array[j]);
        last_swapped = j;
      }
    }
    i = last_swapped;
  }while(i<n);
}
