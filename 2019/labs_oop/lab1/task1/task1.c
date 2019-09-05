//B текстовом файле хранится последовательность целых чисел.
//Получить типизованный файл из неповторяющихся чисел текстового файла.

#include <stdio.h>
#include <stdlib.h>

int file_search(FILE* f,int num){
    long int start_pos=ftell(f);
    int temp,count,flag=1;
    count=0;
    fseek(f,0,SEEK_SET);
    while((fscanf(f,"%d",&temp)!=EOF)&&flag){
        if(temp==num){
            count++;
        }
        if(count>=2) flag=0;
    }
    fseek(f,start_pos,SEEK_SET);
    return !flag;
}

char in_str[255]="input.txt";
char out_str[255]="output.bin";


int main(){
    FILE* fin=fopen(in_str,"r");
    FILE* fout=fopen(out_str,"wb+");
    int temp;
    while (fscanf(fin,"%d",&temp)!=EOF){
        if(!file_search(fin,temp))
        fwrite(&temp,sizeof(temp),1,fout);
    }
    return 0;
}
