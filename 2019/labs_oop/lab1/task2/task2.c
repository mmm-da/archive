//Дан файл, число компонент которого кратно четырем. Файл состоит из
//целых чисел не равных нулю, число положительных компонент файла
//равно числу отрицательных. Преобразовать файл так, чтобы два положи-
//тельных числа чередовались с двумя отрицательными.
#include <stdio.h>
#include <stdlib.h>

int file_search(FILE* f,long int *pos,char mode){
    int temp=0,flag=1;
    fseek(f,*pos,SEEK_SET);
    while((fscanf(f,"%d",&temp)!=EOF)){
        if(mode){
            if(temp>0){
                *pos=ftell(f);
                return temp;
            }
        }
        else{
            if(temp<0){
                *pos=ftell(f);
                return temp;
            }
        }
    }
}

char in_str[255]="input.txt";
char out_str[255]="output.bin";


int main(){
    FILE* fin=fopen(in_str,"r");
    FILE* fout=fopen(out_str,"wb+");
    int temp;
    fseek(fin,0,SEEK_END);
    long int size=ftell(fin);
    fseek(fin,0,SEEK_SET);
    long int count=0,minus_pos=0,plus_pos=0;
    while (count<size){
        temp=file_search(fin,&plus_pos,1);
        fwrite(&temp,sizeof(temp),1,fout);
        count++;
        temp=file_search(fin,&plus_pos,1);
        fwrite(&temp,sizeof(temp),1,fout);
        count++;
        temp=file_search(fin,&minus_pos,0);
        fwrite(&temp,sizeof(temp),1,fout);
        count++;
        temp=file_search(fin,&minus_pos,0);
        fwrite(&temp,sizeof(temp),1,fout);
        count++;
    }
    return 0;
}
