#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define ACC 0.0000001

double count_of_info(double A){
    return(-log2(A));
}

double entropy_Shenon(double *A,unsigned count){
    double sum=0;
    for(int i=0;i<count;i++){
        sum+=count_of_info(A[i])*A[i];
    }
    return sum;
}

double entropy_Hartley(double *A,unsigned count){
    return log2(count);
}
double scan_prob(){
    char c;
    int nm = 0;
    int dnm = 1;
    fflush(stdin);
    c = getchar();
    while (c != ' ' && c != '\n' && c != '.' && c != '/' && c != ','){
        if((c>='0')&&(c<='9')){
            nm *= 10;
            nm += c - '0';
        }
        c = getchar();
    }
    if (c == ' ' || c == '\n'){
        return nm;
    }
    if (c == '/' || c == '\\'){
        dnm=0;
        while(c != ' ' && c != '\n'){
            if((c>='0')&&(c<='9')){
                dnm *= 10;
                dnm += c - '0';
            }
            dnm*=10;
            c = getchar();
        }
        dnm/=10;
        double a = (double)nm / (double)dnm;
        return a;
    }
    if (c == ',' || c == '.'){
        int dnm = 1;
        while(c != ' ' && c != '\n'){
            if((c>='0')&&(c<='9')){
                nm *= 10;
                nm += c - '0';
            }
            dnm*=10;
            c = getchar();
        }
        double a = (double)nm / (double)(dnm/10);
        return a;
    }
    return -1;
}


double* scan_probs(unsigned *count){
    fflush(stdin);
    printf("Введите кол-во значений случайной величины: ");
    scanf("%u",count);
    double* temp=malloc(sizeof(*temp)*(*count));
    double t;
    int result_count=*count;
    getchar();
    printf("Введите вероятности значений случайной величины через пробел: ");
    for(int i=0;i<(*count);i++){
        t=scan_prob();
        if((t-0.0)>ACC){
            temp[i]=t;
        }
        else result_count--;
    }
    double sum=0;
    for(int i=0;i<(*count);i++) sum+=temp[i];
    if(sum>(1+ACC)){
        printf("Сумма вероятностей больше 1");
        exit(1);
    }
    *count=result_count;
    return temp;
}

double r_ratio(double *A,unsigned count){
    return 1-(entropy_Shenon(A,count)/entropy_Hartley(A,count));
}

int check_probs(double* A,unsigned count){
    double check = A[0];
    int i=0;
    while((A[i]==check)&&(i<count)){
        i++;
    }
    return !(i<count);
}

int main(){
    setlocale(LC_ALL, "Rus");
    unsigned count;
    char mode='Y',flag=1;
    while(((mode=='y')||(mode=='Y'))){
        double* probs=scan_probs(&count);

        if(count == 1){
            printf("Количество информации по Шеннону: %lf\n",count_of_info(*probs));
        }
        else{
            if(check_probs(probs,count)){
                printf("Энтропия по Шеннону: %lf\n",entropy_Shenon(probs,count));
                printf("Энтропия по Хартли: %lf\n",entropy_Hartley(probs,count));
                printf("Коэффицент избыточности: %lf\n",r_ratio(probs,count));
            }
            else{
                printf("Энтропия по Шеннону: %lf\n",entropy_Shenon(probs,count));
                printf("Энтропия по Хартли: %lf\n",entropy_Hartley(probs,count));                
                printf("Коэффицент избыточности: %lf\n",r_ratio(probs,count));
            }
        }
        free(probs);
        printf("Продолжить работу программы? [Y/n]:");
        fflush(stdin);
        fflush(stdout);
        getchar();
        scanf("%c",&mode);
        printf("\n");
    }
}
