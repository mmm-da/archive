#include "svg_graph.h"
void svg_init(FILE *file){
    fprintf(file,"<?xml version=%c1.0%c encoding=%cUTF-8%c standalone=%cno%c?>\n",34,34,34,34,34,34);
    fprintf(file,"<svg version = \"1.1\" baseProfile = \"full\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink = \"http://www.w3.org/1999/xlink\" xmlns:ev=\"http://www.w3.org/2001/xml-events\" width=\"%d\" height=\"%d\">\n",BLOCK_SIZE*BLOCK_COUNT,BLOCK_SIZE*BLOCK_COUNT);
}

void svg_debugmap(FILE *file){
    int x,y;
    fprintf(file,"<!-- DEBUG SHEET -->");
    for(x=1;x<BLOCK_COUNT;x++){
        for(y=1;y<BLOCK_COUNT;y++){
            fprintf(file,"  <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"none\" stroke=\"black\" stroke-width=\"%d\"/>\n"
            ,BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE/20);
        }
    }
}

void svg_start_icon(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+x*BLOCK_SIZE+BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/20);
    fprintf(file,"      <circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"white\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/5,BLOCK_SIZE/20);
}

void svg_end_icon(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+x*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/20);
    fprintf(file,"      <circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"white\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/5,BLOCK_SIZE/20);
}

void svg_mid_line(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+x*BLOCK_SIZE+BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/20);
}

void svg_right_edge_line(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+(x+1)*BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE,BORDER_SIZE+(x+1)*BLOCK_SIZE,BORDER_SIZE+(y+1)*BLOCK_SIZE,BLOCK_SIZE/20);
}

void svg_left_edge_line(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE,BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+(y+1)*BLOCK_SIZE,BLOCK_SIZE/20);

}

void svg_right_up_edge_semiline(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+(x+1)*BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+(x+1)*BLOCK_SIZE,BORDER_SIZE+(y+1)*BLOCK_SIZE,BLOCK_SIZE/20);
}

void svg_right_down_edge_semiline(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+(x+1)*BLOCK_SIZE,BORDER_SIZE+(y)*BLOCK_SIZE,BORDER_SIZE+(x+1)*BLOCK_SIZE,BORDER_SIZE+(y)*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/20);
}

void svg_left_up_edge_semiline(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+(y+1)*BLOCK_SIZE,BLOCK_SIZE/20);

}

void svg_left_down_edge_semiline(FILE *file,unsigned x,unsigned y){
    fprintf(file,"      <line  x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+(y)*BLOCK_SIZE,BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+(y)*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/20);
}

void svg_block_icon(FILE *file,char *str, unsigned x,unsigned y){
    fprintf(file,"      <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"none\" stroke=\"black\" stroke-width=\"%d\"/>\n",BORDER_SIZE+x*BLOCK_SIZE,BORDER_SIZE+y*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE/20);
    fprintf(file,"      <text x=\"%d\" y=\"%d\" text-anchor=\"middle\" alignment-baseline=\"middle\" style=\"font-size:%dpx\">%s</text>\n",BORDER_SIZE+x*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/2,str);
}

void svg_print_text(FILE *file,char *str,unsigned x,unsigned y){
    fprintf(file,"      <text x=\"%d\" y=\"%d\" text-anchor=\"middle\" alignment-baseline=\"middle\" style=\"font-size:%dpx\">%s</text>\n",BORDER_SIZE+(x)*BLOCK_SIZE+BLOCK_SIZE/2,BORDER_SIZE+y*BLOCK_SIZE+BLOCK_SIZE/2,BLOCK_SIZE/2,str);
}

void svg_close(FILE *file){
    fprintf(file,"</svg>\n");
    fclose(file);
}

void svg_build_brackets(FILE *file,unsigned width,unsigned height){
    if(height==1){
        svg_start_icon(file,1,1);
        svg_end_icon(file,width*2+3,1);
    }
    else{
        svg_start_icon(file,1,height);
        svg_end_icon(file,2*width+5,height);
        svg_right_up_edge_semiline(file,2,1);
        svg_left_up_edge_semiline(file,2*width+4,1);
        svg_mid_line(file,2,height);
        svg_mid_line(file,2*width+4,height);
        svg_right_down_edge_semiline(file,2,2*height-1);
        svg_left_down_edge_semiline(file,2*width+4,2*height-1);
        for(int i=2;i<2*height-1;i++){
            svg_right_edge_line(file,2,i);
            svg_left_edge_line(file,2*width+4,i);
        }
    }
}

unsigned count_of_dis(char* str,unsigned size){
    unsigned counter=0;
    for(int i=0;i<size;i++){
        if(str[i]=='+'){
            counter++;
        }
    }
    return counter;
}

unsigned max_of_con(char* str,unsigned size){
    unsigned current_count=0,max=0;
    for(int i=0;i<size;i++){
        switch (str[i]) {
            case '(' :
               current_count=0;
               break;
            case '*' :
                current_count++;
               break;
             case ')':
                if(current_count>max){
                    max=current_count;
                }
               break;
        }
    }
    return max;
}

void svg_build_graph(FILE *file,char *str,unsigned size){
    //временная строка для вывода переменной в блок j-индекс для позиционирования в этой строке
    int j=0,k=0;
    char *buffer=(char*)malloc(sizeof(char)*50);
    //подсчет кол-ва дизъюнкций
    unsigned height=count_of_dis(str,size);
    //поиск максимального кол-ва конъюнкций в дизъюнктах
    unsigned width=max_of_con(str,size);
    //построение левых и правых вертикальных соединительных линий
    svg_build_brackets(file,width+1,height+1);
    unsigned x=0,y=1;
    char block_state=2;
    //если высота = 1 то просто строим линейную схему
    if(height==0){
        for(int i=2;i<(width+1)*2+3;i+=2){
            svg_mid_line(file,i,y);
        }
        x=3;
        for(int i=1;i<size;i++){
            if((str[i]=='*')||(str[i]==')')){
                buffer[j]='\0';
                switch (block_state) {
                    case 2:
                    svg_block_icon(file,buffer,x,y);
                    break;
                    case 1:
                    svg_mid_line(file,x,y);
                    break;
                }
                block_state=2;
                x+=2;
                j=0;
            }
            else{
                switch (str[i]) {
                    case '0':
                    block_state=0;
                    break;
                    case '1':
                    block_state=1;
                    break;
                    case '!':
                    buffer[j]='&'; j++; buffer[j]='#'; j++; buffer[j]='1'; j++; buffer[j]='7'; j++; buffer[j]='2'; j++; buffer[j]=';'; j++;
                    break;
                    default:
                    buffer[j]=str[i];
                    j++;
                }
            }
        }
        svg_print_text(file,str_prep_to_out(str),width+3,height+3);
    }
    //иначе строим линейную схему для каждого дизъюнкта выравнивая кол-во элементов
    else{
        unsigned count_var=0;
        y=0;
        int start_of_bracket,end_of_bracket;
        for(int i=0;i<size;i++){
        switch (str[i]) {
            case '(' :
               count_var=0;
               start_of_bracket=i+1;
               y++;
               break;
            case '*' :
               count_var++;
               break;
            case ')' :
                end_of_bracket=i;
                x=3;
                //начальные горизонтальные линии
                for(int i=0;i<width-count_var+1;i++){
                    svg_mid_line(file,x+i,y);
                    svg_mid_line(file,2*width+5-i,y);
                }
                x=4+width-count_var;
                k=start_of_bracket;
                //построение блоков реле
                for(int i=0;i<=2*count_var;i+=2){
                    j=0;
                    //заполнение блоков текстом
                    while((str[k]!='*')&&(str[k]!=')')){
                        switch (str[k]) {
                            case '0':
                            block_state=0;
                            break;
                            case '1':
                            block_state=1;
                            break;
                            case '!':
                            buffer[j]='&'; j++; buffer[j]='#'; j++; buffer[j]='1'; j++; buffer[j]='7'; j++; buffer[j]='2'; j++; buffer[j]=';'; j++;
                            break;
                            default:
                            buffer[j]=str[k];
                            j++;
                            break;

                        }
                         k++;
                    }
                    buffer[j]='\0';
                    k++;
                    switch (block_state) {
                        case 2:
                        svg_block_icon(file,buffer,x+i,y);
                        break;
                        case 1:
                        svg_mid_line(file,x+i,y);
                        break;
                        }
                        //k++;
                        block_state=2;
                    //}

                    //если проверяет состояние блока и отрисовываем его в соответствии с состоянием
                }
                //построение соединительных горизонтальных линий
                for(int i=1;i<=2*count_var;i+=2){
                    svg_mid_line(file,x+i,y);
                }
                //переход на следующую строку блока
                y++;
              break;
        }
     }
     svg_print_text(file,str_prep_to_out(str),2*width-width/2+3,2*height+3);
    }
}

char* str_prep_to_out(char* in){
    unsigned sizeof_str=strlen(in);
    char* out=(char*)malloc(sizeof_str*sizeof(char));
    int j=0;
    for(int i=0;i<sizeof_str;i++){
        switch (in[i]) {
            case '!':
            out[j]='&'; j++; out[j]='#'; j++; out[j]='1'; j++; out[j]='7'; j++; out[j]='2'; j++; out[j]=';'; j++;
            break;
            case '*':
            out[j]='&'; j++; out[j]='#'; j++; out[j]='8'; j++; out[j]='7'; j++; out[j]='4'; j++; out[j]='3'; j++; out[j]=';'; j++;
            break;
            case '+':
            out[j]='&'; j++; out[j]='#'; j++; out[j]='8'; j++; out[j]='7'; j++; out[j]='4'; j++; out[j]='4'; j++; out[j]=';'; j++;
            break;
            default:
            out[j]=in[i];
            j++;
        }
    }
    out[j]='\0';
    j++;
    return out;
}
