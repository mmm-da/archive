#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main (int argc, char * argv[]) {
    setlocale(LC_ALL, "Rus");
    int i;
    if(argc==1) {
        printf("sintax error \"a -h\" to help");
    }
    else{
    switch (argv[1][1]) {
        case 'h' :
            printf("L33T_translator with cyrillic support \n-h :help\n-t STRING :translate");
        break;
        case 't' :
            i=0;
            while(argv[2][i]!='\0'){
                switch (argv[2][i]){
                    case 'a':
                        printf("4");
                    break;
                    case 'b':
                        printf("8");
                    break;
                    case 'c':
                        printf("(");
                    break;
                    case 'd':
                        printf("|)");
                    break;
                    case 'e':
                        printf("3");
                    break;
                    case 'f':
                        printf("ph");
                    break;
                    case 'g':
                        printf("6");
                    break;
                    case 'h':
                        printf("|-|");
                    break;
                    case 'i':
                        printf("!");
                    break;
                    case 'j':
                        printf(")");
                    break;
                    case 'k':
                        printf("|<");
                    break;
                    case 'l':
                        printf("1");
                    break;
                    case 'm':
                        printf("/V\\");
                    break;
                    case 'n':
                        printf("/\\/");
                    break;
                    case 'o':
                        printf("0");
                    break;
                    case 'p':
                        printf("|>");
                    break;
                    case 'q':
                        printf("9");
                    break;
                    case 'r':
                        printf("|2");
                    break;
                    case 's':
                        printf("$");
                    break;
                    case 't':
                        printf("7");
                    break;
                    case 'u':
                        printf("|_|");
                    break;
                    case 'v':
                        printf("\\/");
                    break;
                    case 'w':
                        printf("\\X/");
                    break;
                    case 'x':
                        printf("*");
                    break;
                    case 'y':
                        printf("'/'");
                    break;
                    case 'z':
                        printf("2");
                    break;
                    case '�':
                        printf("4");
                    break;
                    case '�':
                        printf("8");
                    break;
                    case '�':
                        printf("\\/");
                    break;
                    case '�':
                        printf("r");
                    break;
                    case '�':
                        printf("|)");
                    break;
                    case '�':
                        printf("3");
                    break;
                    case '�':
                        printf("}|{");
                    break;
                    case '�':
                        printf("'/_");
                    break;
                    case '�':
                        printf("|/|");
                    break;
                    case '�':
                        printf("|<");
                    break;
                    case '�':
                        printf("/\\");
                    break;
                    case '�':
                        printf("/V\\");
                    break;
                    case '�':
                        printf("|-|");
                    break;
                    case '�':
                        printf("0");
                    break;
                    case '�':
                        printf("/7");
                    break;
                    case '�':
                        printf("|>");
                    break;
                    case '�':
                        printf("(");
                    break;
                    case '�':
                        printf("7");
                    break;
                    case '�':
                        printf("'/");
                    break;
                    case '�':
                        printf("qp");
                    break;
                    case '�':
                        printf("*");
                    break;
                    case '�':
                        printf("||_");
                    break;
                    case '�':
                        printf("'-|");
                    break;
                    case '�':
                        printf("LLI");
                    break;
                    case '�':
                        printf("LLL");
                    break;
                    case '�':
                        printf("'b");
                    break;
                    case '�':
                        printf("bl");
                    break;
                    case '�':
                        printf("b");
                    break;
                    case '�':
                        printf("-)");
                    break;
                    case '�':
                        printf("1");
                    break;
                    case '�':
                        printf("9|");
                    break;
                    case '"':
                    break;
                    case ' ':
                    printf("    ");
                    break;
                    default:
                    printf("%c",argv[2][i]);
                }
                i++;
            }
        break;
        default:
        printf("argc =%d\n",argc );
        printf("sintax error \"a -h\" to help");
    }}
    return 0;
}
