#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

void print_IP_from_name(char* name){
    struct addrinfo *ptr = NULL;
    struct addrinfo *result = NULL;
    struct addrinfo hints;
    struct sockaddr_in  *sockaddr_ipv4;
    struct sockaddr_in saGNI;
    getaddrinfo(name, 0, &hints, &result);
    printf("IP list: \n"); 
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
            if (ptr->ai_family == AF_INET) {
                sockaddr_ipv4 = (struct sockaddr_in *) ptr->ai_addr;
                printf("%s\n",inet_ntoa(sockaddr_ipv4->sin_addr));
            }
        }
}

void print_name_from_IP(char* ip){
    char hostname[NI_MAXHOST];
    char servInfo[NI_MAXSERV];
    struct sockaddr_in saGNI;
    saGNI.sin_family = AF_INET;
    saGNI.sin_addr.s_addr = inet_addr(ip);
    saGNI.sin_port = htons(27015);
    getnameinfo((struct sockaddr *) &saGNI, sizeof(struct sockaddr), hostname, NI_MAXHOST, servInfo, NI_MAXSERV, NI_NUMERICSERV);
    printf("Hostname: %s\n",hostname);
    printf("Server Info: %s\n",servInfo);
}
