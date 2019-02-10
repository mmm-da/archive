#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "task.h"

int main(){
    char str1[50],str2[50];
    list* poly1,*poly2,*poly3;
    scanf("%s",&str1);
    fflush(stdin);
    scanf("%s",&str2);
    poly1=str_to_list(str1);
    poly2=str_to_list(str2);
    poly3=sum_poly(poly1,poly2);
    print_poly(poly3);

    return 0;
}
