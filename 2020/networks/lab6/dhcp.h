#include <stdlib.h>
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>

void print_iface_info(){
    PIP_INTERFACE_INFO pInfo;
    pInfo = (IP_INTERFACE_INFO *) malloc( sizeof(IP_INTERFACE_INFO) );
    ULONG ulOutBufLen = 0;

    if ( GetInterfaceInfo(pInfo, &ulOutBufLen) == ERROR_INSUFFICIENT_BUFFER) {
        free(pInfo);
        pInfo = (IP_INTERFACE_INFO *) malloc (ulOutBufLen);
    }

    if ((GetInterfaceInfo(pInfo, &ulOutBufLen)) == NO_ERROR ) {
        printf("Num Adapters: %ld\n", pInfo->NumAdapters);
        for(int i=0;i<pInfo->NumAdapters;i++){
            printf("Adapter[%ld] Name: %ws\n",pInfo->Adapter[0].Index, pInfo->Adapter[0].Name);
        }
    }

    free(pInfo);  
};

void renewIP(){
    print_iface_info();
    printf("Select index of iface to renew IP: ");
    int index;
    scanf("%d",index);
    PIP_INTERFACE_INFO pInfo;
    pInfo = (IP_INTERFACE_INFO *) malloc( sizeof(IP_INTERFACE_INFO) );
    ULONG ulOutBufLen = 0;

    if ( GetInterfaceInfo(pInfo, &ulOutBufLen) == ERROR_INSUFFICIENT_BUFFER) {
        free(pInfo);
        pInfo = (IP_INTERFACE_INFO *) malloc (ulOutBufLen);
    }

    if ((GetInterfaceInfo(pInfo, &ulOutBufLen)) == NO_ERROR ) {
        IpRenewAddress(&pInfo->Adapter[index]);
        printf("Renew complete\n");
    }
    free(pInfo);
}

void releaseIP(){
    print_iface_info();
    printf("Select index of iface to release IP: ");
    int index;
    scanf("%d",index);
    PIP_INTERFACE_INFO pInfo;
    pInfo = (IP_INTERFACE_INFO *) malloc( sizeof(IP_INTERFACE_INFO) );
    ULONG ulOutBufLen = 0;

    if ( GetInterfaceInfo(pInfo, &ulOutBufLen) == ERROR_INSUFFICIENT_BUFFER) {
        free(pInfo);
        pInfo = (IP_INTERFACE_INFO *) malloc (ulOutBufLen);
    }

    if ((GetInterfaceInfo(pInfo, &ulOutBufLen)) == NO_ERROR ) {
        IpRenewAddress(&pInfo->Adapter[index]);
        printf("Release complete\n");
    }
    free(pInfo);
}