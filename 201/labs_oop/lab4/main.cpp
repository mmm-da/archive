#include <stdio.h>
#include <malloc.h>

class Array{
    int *ptr;
    int n;
    public:
        Array(unsigned size){
            n=size;
            ptr=(int*)malloc(sizeof(int)*n);
            for(int i=0;i<n;i++) ptr[i]=0;
        };
        void copy(const Array a){
            int i=0;
            while((i<n)&&(i<a.n)){
                ptr[i]=a.ptr[i];
            }
        }
        void scan(){
            for(int i=0;i<n;i++) scanf("%d",&ptr[i]);
        };
        void print(){
            for(int i=0;i<n;i++) printf("%d ",ptr[i]);
            printf("\n");
        };
        void sort(){
            int i,j,temp;
            for(j=1;j<n;j++){
                temp=ptr[j];
                i=j-1;
                while((i>0)&&(ptr[i]>temp)){
                    ptr[i+1]=ptr[i];
                    i--;
                }
                ptr[i+1]=temp;
            }
        };

         Array operator -= (const Array a2){
            int size;
            if(this->n >= a2.n){
                size=a2.n;
            }
            else size=this->n;
            for(int i=0;i<size;i++) this->ptr[i]=this->ptr[i]-a2.ptr[i];
        };

        friend Array operator ! (const Array a){
            Array temp(a.n);
            for(int i=0;i<temp.n;i++){
                temp.ptr[i]=a.ptr[i]*-1;
            }
            return temp;
        };
};

int main(){
    int n=5;
    Array test(n);
    test.scan();
    test.print();
    test.sort();
    test.print();
    Array test1(n);
    test1 = !test;
    test1.print();
    test1-=test;
    test1.print();
    return 0;
}
