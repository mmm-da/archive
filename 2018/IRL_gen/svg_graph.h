#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BLOCK_COUNT 50 //количество блоков
#define BLOCK_SIZE 50 // размер блока в пикселях
#define BORDER_SIZE 20 // отступы от края


void svg_init(FILE *file);

void svg_debugmap(FILE *file);

void svg_close(FILE *file);

void svg_start_icon(FILE *file,unsigned x,unsigned y); //отрисовывает знак начала цепи в блоке x:y
void svg_end_icon(FILE *file,unsigned x,unsigned y); //отрисовывает знак конца цепи в блоке x:y


void svg_mid_line(FILE *file,unsigned x,unsigned y); //отрисовывает линию по середине блока

void svg_right_up_edge_semiline(FILE *file,unsigned x,unsigned y); //отрисовывает  верхную половину линию по правому краю блока
void svg_right_down_edge_semiline(FILE *file,unsigned x,unsigned y); //отрисовывает нижнюю половину линию по правому краю блока

void svg_left_up_edge_semiline(FILE *file,unsigned x,unsigned y); //отрисовывает  верхную половину линию по левому краю блока
void svg_left_down_edge_semiline(FILE *file,unsigned x,unsigned y); //отрисовывает  нижнюю половину линию по левому краю блока

void svg_right_edge_line(FILE *file,unsigned x,unsigned y);//отрисовывает  линию по правому краю блока
void svg_left_edge_line(FILE *file,unsigned x,unsigned y);//отрисовывает  линию по левому краю блока


void svg_block_icon(FILE *file,char *str, unsigned x,unsigned y); //отрисовывает блок реле

void svg_build_brackets(FILE *file,unsigned height,unsigned width);
void svg_build_graph(FILE *file,char *str,unsigned size);

void svg_print_text(FILE *file,char *str,unsigned x,unsigned y);
char* str_prep_to_out(char* in);
unsigned count_of_dis(char* str,unsigned size);
unsigned max_of_con(char* str,unsigned size);
