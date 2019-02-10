#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg_graph.h"

int main(){
    FILE *f_in;
    char name[128];
    if ((f_in = fopen("result.svg", "w"))==NULL){
        printf("Unable to open");
        return 1;
    }
    char str[100]="(0*a*0*0*!A)+(0*a*0*0*!A)+(0*a*0*0*!A)";
    scanf("%s", str);
    svg_init(f_in);
    //svg_debugmap(f_in);
    svg_build_graph(f_in,str,strlen(str));
    svg_close(f_in);
    return 0;
}
