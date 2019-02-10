#include <stdio.h>

int strcmp(char* s1, char* s2)
{
int i = 0;
    while (s1[i] == s2[i] && s1[i]!='\0' && s2[i] !='\0'){
            i++;
        }
    return s2[i] - s1[i];
}



 int main()
 {
     FILE *f,*g;
     char tStr1[255],tStr2[255];
     char flag,t;
     f = fopen("f.txt","r+");
     g = fopen("g.txt","r");
     while (!feof(g))
     {
            fgets(tStr1,255,g);
            flag=1;
            printf("\n6");
            printf("\n6.5 %s %s",tStr1,tStr2);
            fseek(f,0,SEEK_SET);
            while (!feof(f) && flag)
            {
                fseek(f,0,t);
                fgets(tStr2,255,f);
                t=strcmp(tStr1,tStr2);
                if (t)
                {
                    flag=0;
                    printf("\n8");
                    fseek(f,0,SEEK_END);
                    printf("\n9");
                    fputs(tStr1,f);
                }
                printf("\n10");
            }

     }
     printf("\nend");
     fclose(f);
     fclose(g);
     //remove("g.txt");


 }
