#include <stdio.h>
#include <malloc.h>
#define T_SIZE 20

char* read_str(char* str)
{
    int i=0;
    int lim=T_SIZE*sizeof(char);
    char c=0,flag=1;
    str=malloc(lim);
    c=getchar();
    while ((c!=EOF)&&(c!='\n'))
    {
        //printf("\n read char -%d",i);
        //printf("\n  char -%c i - %d",c,i);
        if (i>=lim)
        {
            lim*=2;
            str=realloc(str,lim);
        }
        str[i]=c;
        c=getchar();
        i++;
        printf("%c",str[i]);
    }
    str[i]='\0';
    str=realloc(str,(i+1)*sizeof(char));
    if (c==EOF) flag=0;
    return flag;
}

char** read_txt()
{
    int i=0;
    char** txt;
    int lim=5*sizeof(char*);
    txt=malloc(lim);
    while(read_str(txt[i]))
    {
        printf("\n read str -%d",i);
        if (i>=lim)
        {
            lim*=2;
            realloc(txt,lim);
        }
        i++;
    }
    return txt;
}

int main()
{
    char** txt;
    printf("start\n");
    txt=read_txt();

}
