#include <stdio.h>
#include <stdlib.h>
#include "../t_info.h"

//Совместная энтропия


int main(){
    double **in_matr,**out_matr,**cmm_matr,**probs;

    
    int mode,n,m;
    printf("Выберите случай ввода (1 - КМИ <p(b/a)>, 2 - КМП <p(a/b)>, 3 - КМО <p(a,b)> ) - ");
    scanf("%d",&mode);
    mode--;
    printf("Введите размерность вводимой матрицы (n,m) - ");
    scanf("%d %d",&n,&m);
    getchar();
    switch (mode) {
        case 0:
            in_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);
            cmm_matr=source_to_common(in_matr,probs,n,m);
            out_matr=common_to_reciver(cmm_matr,probs,n,m);
        break;
        case 1:
            out_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);
            cmm_matr=reciver_to_common(out_matr,probs,n,m);
            in_matr=common_to_source(cmm_matr,probs,n,m);
        break;
        case 2:
            cmm_matr=scan_chmatr(n,m,mode);
            probs=scan_probs(n,m,mode);
            in_matr=common_to_source(cmm_matr,probs,n,m);
            out_matr=common_to_reciver(cmm_matr,probs,n,m);
        break;
    }
    print_chmatr(in_matr,probs,n,m,0);
    print_chmatr(out_matr,probs,n,m,1);
    print_chmatr(cmm_matr,probs,n,m,2);
    print_entr(cmm_matr,in_matr,out_matr,probs,n,m);
}
