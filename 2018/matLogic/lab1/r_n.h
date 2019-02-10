#ifndef REV_NOTE
#define REV_NOTE

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

enum operatons{INV='!',MLT='*',SUM='+',OBR='(',CBR=')'};
int str_lenght(char* str);
char strsearch(char* str,char c);
int revers_note(char* str,char* result);
#endif
