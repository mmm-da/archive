#ifndef _ARP_WRAPPER_H
#define _ARP_WRAPPER_H

#include <stdlib.h>
#include <stdio.h>
#include <winsock.h>
#include <iphlpapi.h>

void print_arp_table(){
    int pos = 0;
    PMIB_IPNETTABLE IPARPTable = NULL;
    DWORD ActualSize = 0;
    GetIpNetTable(IPARPTable, &ActualSize, 1);
    IPARPTable = (PMIB_IPNETTABLE)malloc(ActualSize);
    if (GetIpNetTable(IPARPTable, &ActualSize, 1) != NO_ERROR) {
        if (IPARPTable)
            free(IPARPTable);
        return;
    }
    DWORD CurrentIndex;
    char Address[256];
    PMIB_IPADDRTABLE IPAddressTable = NULL;
    ActualSize = 0;
    GetIpAddrTable(IPAddressTable, &ActualSize, 1);
    IPAddressTable = (PMIB_IPADDRTABLE)malloc(ActualSize);
    GetIpAddrTable(IPAddressTable, &ActualSize, 1);
    CurrentIndex = -100;//индекс адаптера
    printf("ARP table\n");
    for (DWORD i = 0; i < IPARPTable->dwNumEntries; i++) {
        char if_str[255];
        if (IPARPTable->table[i].dwIndex != CurrentIndex) {
            CurrentIndex = IPARPTable->table[i].dwIndex;
            IN_ADDR InAddress;
            for (DWORD j = 0; j < IPAddressTable->dwNumEntries; j++) {
                if (CurrentIndex != IPAddressTable->table[j].dwIndex)
                    continue;
                InAddress.S_un.S_addr = IPAddressTable->table[j].dwAddr;
                strcpy(Address, inet_ntoa(InAddress));
            }
            printf("\nInterface: %s ~ %X\n",Address,CurrentIndex);
        }
        switch (IPARPTable->table[i].dwType) {
            case 1:
                printf("Other      ");
            break;
            case 2:
                printf("Wrong      ");
            break;
            case 3:
                printf("Dynamic    ");
            break;
            case 4:
                printf("Static     ");
            break;
            default:
                printf("None       ");
        }
        IN_ADDR InAddress;
        InAddress.S_un.S_addr = IPARPTable->table[i].dwAddr;
        printf("%12s      ",inet_ntoa(InAddress));
        for (int k = 0; k < 6; k++){
            if (IPARPTable->table[i].bPhysAddr[k] < 0x10){
                printf("%X",IPARPTable->table[i].bPhysAddr[k]);
            } else {
                printf("%X",IPARPTable->table[i].bPhysAddr[k]);
            }
            if (k != 5) printf(":");
        }
        pos++;
        printf("\n");
    }
};

void getMac(const char *IP) {
    DWORD ActualSize = 0;
    PMIB_IPNETTABLE IPAddressTable = NULL;
    GetIpNetTable(IPAddressTable, &ActualSize, 1);
    IPAddressTable = (PMIB_IPNETTABLE)malloc(ActualSize);
    GetIpNetTable(IPAddressTable, &ActualSize, 1);
    DWORD InetAddress = inet_addr(IP);
    if (InetAddress == INADDR_NONE) {
        printf("Wrong IP adress\n");
        return;
    }
    char SearchFlag = 1;
    for (DWORD i = 0; i < IPAddressTable->dwNumEntries; i++) {
        if (InetAddress == IPAddressTable->table[i].dwAddr) {
            printf("MAC: \n");
            for (int k = 0; k < 6; k++){
                if (IPAddressTable->table[i].bPhysAddr[k] < 0x10){
                    printf("%X",IPAddressTable->table[i].bPhysAddr[k]);
                } else {
                    printf("%X",IPAddressTable->table[i].bPhysAddr[k]);
                }
                if (k != 5) printf(":");
            }
            printf(" on iface - %h\n",IPAddressTable->table[i].dwIndex);
            SearchFlag = 0;
        }
    }
    if (SearchFlag) printf("MAC doesn't exist\n");
};

DWORD addIpNetEntry(const char * ip, const char * mac, unsigned iface){
    DWORD InetAddress = inet_addr(ip);
    if (InetAddress == INADDR_NONE) {
        printf("Wrong IP adress\n");
        return 1;
    }
    MIB_IPNETROW ARPRow;
    ARPRow.dwIndex = iface;
    ARPRow.dwPhysAddrLen = 6;
    ARPRow.dwAddr = InetAddress;
    ARPRow.dwType = MIB_IPNET_TYPE_STATIC;
    switch (CreateIpNetEntry(&ARPRow)) {
    case ERROR_ACCESS_DENIED:
        printf("ACCESS DENIED\n");
        break;
    case NO_ERROR:
        printf("Record created\n");
        break;
    default:
        printf("Record doesn't created\n");
    }
    return 0;
};

DWORD dropIpNetEntry(const char * ip, unsigned iface){
    DWORD InetAddress = inet_addr(ip);
    if (InetAddress == INADDR_NONE){
        printf("Wrong IP adress\n");
        return 1;
    }
    MIB_IPNETROW ARPRow;
    ARPRow.dwIndex = iface;
    ARPRow.dwAddr = InetAddress;
    switch (DeleteIpNetEntry(&ARPRow)) {
        case ERROR_ACCESS_DENIED:
        printf("ACCESS DENIED\n");
        break;
         case NO_ERROR:
        printf("Record created\n");
        break;
         default:
        printf("Record doesn't created\n");
    }
};

#endif