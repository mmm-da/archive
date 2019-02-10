#include <stdio.h>
#include <stdlib.h>
#include "lab11_lib.h"
#include <mem.h>


void  usort(void *arr,int size,int el_size,char (*atr) (const void*,const void*))
{
    void *x,*y,*t;
    int j=0;
    void *am;
    char flag=1;
    int min,i;
    t=malloc(el_size);
    while ((j<(size-1))&&flag)
    {
        flag=0;
        min=j;
        for (i=j;i<(size-1)-j;i++)
        {
            x=(char*)arr+(el_size*i);
            y=(char*)arr+(el_size*(i+1));
            if (atr(x,y))
            {
                memcpy(t,x,el_size);
                memcpy(x,y,el_size);
                memcpy(y,t,el_size);
                flag=1;
            }
            x=(char*)arr+(el_size*i);
            am=(char*)arr+(el_size*min);
            if (!atr(x,am)) min=i;

        }
        if (min!=j)
        {
            x=(char*)arr+(el_size*j);
            memcpy(t,x,el_size);
            memcpy(x,am,el_size);
            memcpy(am,t,el_size);
        }
        j++;
    }
    free(t);
}


int cmp_l(const void *a, const void *b){
	t_std *s1, *s2;
	s1 = *((t_std **)a);
	s2 = *((t_std **)b);
	char *name1, *name2;
	name1 = s1->name;
	name2 = s2->name;
    while ((*name1 == *name2) && (*name1!='\0') && (*name2!='\0')){
         name1++;
    	 name2++;
    }
	return *name1 < *name2;
}

int cmp_avr (const void *a, const void *b) {
    int avr_a, avr_b;
    t_std *s1, *s2;
    s1 = *((t_std **)a);
	s2 = *((t_std **)b);
	avr_a = s1->m1 + s1->m2 + s1->m3;
    avr_b = s2->m1 + s2->m2 + s2->m3;
    return avr_a > avr_b;
}

int read_student(FILE *f, t_std **x){
    t_std *s;
    s = *x = (t_std *)malloc(sizeof(t_std));
    s->name = (char *)malloc(30*sizeof(t_std));
    if (fgets(s->name, 30, f) != NULL){
        fscanf(f, "%i, %i, %i\n", &(s->m1), &(s->m2), &(s->m3));
    } else return EOF;
    return 0;
}

void write_student(t_std *s){
    printf("%s", s->name);
    printf("%i, %i, %i\n", s->m1, s->m2, s->m3);
}
