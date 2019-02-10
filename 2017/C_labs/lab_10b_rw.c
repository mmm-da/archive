#include <stdio.h>

int main(){
    FILE *f;
    char name[20], c;
    int t;
    printf("Enter filename: ");
    scanf("%s", name);
    gets(&c);
    printf("Choose: read or write (r/w)? ");
    scanf("%c", &c);
    if (c=='w'){
        if ((f=fopen(name, "wb"))!=NULL){
            printf("Press ctrl+Z to finish\n");
            while (scanf("%i", &t)!=EOF){
                fwrite(&t, sizeof(t), 1, f);
            }
            fclose(f);
        }else{
        printf("ERROR!");
        }
    }else if (c=='r'){
        if ((f=fopen(name, "rb"))!=NULL){
            while (fread(&t, sizeof(t), 1, f)){
                printf("%i ", t);
            }
            fclose(f);
            }else{
        printf("ERROR!");
        }
    }else printf("Wrong answer");
    return 0;
}
