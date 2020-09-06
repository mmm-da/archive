#include <stdio.h>
#include <string.h>
#include "crossIO.h"
#include <stdlib.h>
#include <stdarg.h>

int cross_printf(char* format,...){
    char* temp_format=malloc(sizeof(char)*strlen(format));
    temp_format=cross_str(format);
    va_list arg;
    int done;
    va_start (arg, temp_format);
    done = vfprintf (stdout, temp_format, arg);
    va_end (arg);
    return done;
}

int cross_fprintf(FILE *file,char* format,...){
    char* temp_format=malloc(sizeof(char)*strlen(format));
    temp_format=cross_str(format);
    va_list arg;
    int done;
    va_start (arg, temp_format);
    done = vfprintf (file, temp_format, arg);
    va_end (arg);
    return done;
}


char* cross_str(unsigned char* str){
    #ifdef _WIN32
        return cross_str_CP866(str);
    #else
        return str;
    #endif
}

char* cross_str_CP866(unsigned char* str){
    char* result_str=malloc(sizeof(unsigned char)*strlen(str));
    int i=0,j=0;
    while(i<strlen(str)){
        if((str[i]>=0xD0)&&(str[i]<=0xD3)){
            i++;
            if((str[i]>=0x90)&&(str[i]<=0xBF)){
                result_str[j]=str[i]-0x10;
                j++;
            }
            else if((str[i]>=0x80)&&(str[i]<=0x8F)){
                result_str[j]=str[i]+0x60;
                j++;
            }
        }
        else{
            result_str[j]=str[i];
            j++;
        }
        i++;
    }
    j++;
    result_str[j]='\0';
    return result_str;
}
