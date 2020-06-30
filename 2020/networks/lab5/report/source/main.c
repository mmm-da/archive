#include <stdlib.h>
#include <stdio.h>
#include "arp_wrapper.h"

int main(){
    print_arp_table();
    getMac("239.192.152.143");
    return 0;
}