#include <stdio.h>
#include <stdlib.h>
#include "lab11_lib.h"
#define NUM_OF_STUD 4

int main()
{
    FILE *f;
    char name[20];
    t_std **a;
    int i;
    char mode;
    a = (t_std **)malloc((NUM_OF_STUD+1)*sizeof(t_std *));
    printf("File name: ");
    scanf("%s", name);
    if ((f = fopen(name, "r"))!=NULL)
    {
        for (i=0; read_student(f, &a[i]) != EOF; i++){};
        printf("Attribute of sorting (L - lexicographically; A - average): ");
        int flag = 0;
        int (*func)(const void *, const void *);
        do
        {
            scanf("%c", &mode);
            if (mode == 'L')
                {
                func = cmp_l;
                flag = 1;
            }
            else if (mode == 'A')
            {
                func = cmp_avr;
                flag = 1;
            }

        }
        while (!flag);
        usort(a,NUM_OF_STUD,sizeof(t_std *), func);
        for (i = 0; i<NUM_OF_STUD; i++)
        {
            write_student(a[i]);
        }
    }
    else puts ("Error! File not found. Please input file path correctly.");
    return 0;
}

