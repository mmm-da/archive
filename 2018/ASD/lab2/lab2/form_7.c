#include "form_7.h"
#include <stdlib.h>
#include <stdio.h>
const int STR_OVER= 100;
const int STR_EMPTY= 101;
const int STR_OUTBORDER= 102;

string1 InitStr(unsigned n)
{
    string1 st;
    st = (string1) malloc(sizeof(string1));
    st->s = (char*) malloc(n+3);
    st->max = n;
    setLenght(0,st);
    st->s[2]=0;
    return st;
};

void WriteToStr(char* oS,string1 st){
  unsigned short i=0;
  unsigned short j=Length(st)+2;
  char flag=1;
  while((oS[i]!='\0')&&(flag)){
      st->s[i+j]=oS[i];
      i++;
  };
  st->s[i+j]=' ';
  if((i+j-2)<st->max){
  setLenght(i+j-2,st);
  }
  else{
    StrError=100;
    exit(StrError);
  }
};

void setLenght(unsigned short size,string1 st){
    if(size<st->max){
    st->s[0]=size>>8;
    st->s[1]=size&255;
    }
    else{
    StrError=100;
    exit(StrError);
    }
};

void InputStr(string1 st){
    unsigned short i= 2;
    while(((st->s[i]=getchar())!='\n')&&(i<st->max)){
      i++;
    }
    if(i>st->max){
      StrError=100;
      printf("ERROR %d",StrError);
      exit(StrError);
    }
    setLenght(i-2,st);
}

void OutputStr(string1 st){
    unsigned short i=2;
    unsigned short j=Length(st);
    if(j==0){
      StrError=101;
      exit(StrError);
    }
    else{
    while(putchar(st->s[i])!='\0') i++;
    }
};

void Delete(string1 s, unsigned Index, unsigned Count){
    unsigned short j=2,i=Index+Count;
    unsigned short size=Length(s);
    if(size+2<Index){
      StrError=102;
      exit(StrError);
    }
    else{
      while(s->s[i+j]!=0){
        s->s[Index+j]=s->s[i+j];
        j++;
      }
    }
    setLenght(size-j+2,s);
}

void Insert(string1 Subs, string1 s, unsigned Index){
    unsigned short s1,s2;
    int i,j=0;
    s1=Length(Subs);
    s2=Length(s);

    if (s->max>=s1+s2){
        StrError=100;
        exit(StrError);
    }
    else{
    for(i=2;i<s1;i++)
    {    s->s[Index+s1+i]=s->s[Index+i];
         s->s[Index+j]=Subs->s[j];
         j++;
    }
    }
    }

void Concat(string1 s1, string1 s2, string1 srez){
    unsigned short t1,t2;
    int i;
    t1=Length(s1);
    t2=Length(s2);
    if (srez->max>=t1+t2){
        StrError=100;
        exit(StrError);
    }
    else{
        setLenght(t1+t2,srez);
        for(i = 2;i<t1+2;i++) srez->s[i]=s1->s[i];
        for(int j = 2;j<t2+2;j++){
            srez->s[i]=s2->s[j];
            i++;
        }
        srez->s[i]=0;
    }
}

void Copy(string1 s, unsigned Index, unsigned Count,string1 Subs){
     unsigned short size=Length(s);
     int i;
     if(size+2<Index){
      StrError=102;
      exit(StrError);
    }
    else{
        if (Subs->max>=Count){
        StrError=100;
        exit(StrError);
        }
        else{
            for(i=2;i<Count;i++){
                s->s[Index+i]=Subs->s[i];
            }
        }
        Subs->s[i]=0;
    }
}


int Comp(string1 s1, string1 s2){
  int i,r=0;
  while((r==0)&&(i!=s1->max)&&(i!=s2->max))
  {
      r=s1->s[i]-s2->s[i];
      i++;
  }
  return r;
};


void DoneStr(string1 st){
   free(st->s);
   free(st);
};

unsigned short Length(string1 st){
    char a=st->s[0];
    char b=st->s[1];
    unsigned short c = (((short)a) << 8) | b;
    return c;
};
