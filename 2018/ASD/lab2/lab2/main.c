#include <stdio.h>
#include <stdlib.h>
#include "form_7.h"
#include <string.h>

char* get_word(char* string, char* word){
	for (; *string!='\0' && *string == ' '; string++);
	for (; *string!='\0' && *string != ' '; string++){
		*word=*string;
		word++;
	}
	*word = '\0';
	return string;
}



string1 SubWord(char *s, unsigned n)
{
    string1 t;
		int i;
    t=InitStr(90);
    char word[99];
    for(i=1;i<n;i++){
      s=get_word(s,word);
		}
    while (*s!='\0'){
      s=get_word(s,word);
			WriteToStr(word,t);
			t->s[Length(t)+3]=' ';
			setLenght(Length(t)+1,t);
    }

		return t;
}

int main()
{
		int n;
		string1 s1,s2;
		s1=InitStr(90);
		char str[90];
		printf("Input n - ");
		scanf("%i",&n);
		fflush(stdin);
		printf("Input str - ");
		gets(str);
		s1=SubWord(str,n);
		OutputStr(s1);
		setLenght((unsigned short)5,s1);

}
