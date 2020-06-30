#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <winsock.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

typedef struct _thread_arg {
	struct sockaddr_in adr;
	int data;
} thread_arg;

DWORD WINAPI send_echo_adr(LPVOID arg) {
	printf("\nReceived packet from client\n");
	printf("Creating thread for response\n");
	printf("Received number: %d\n", ((thread_arg *)arg)->data);
	printf("Send echo packet\n");
	int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (s == SOCKET_ERROR) {
		perror("Socket creating error\n");
		return 1;
	};
	int ret_val = sendto(
		s, 
		(char *)(&((thread_arg *)arg)->data), 
		sizeof(int), 0, 
		(SOCKADDR *)&((thread_arg *)arg)->adr, 
		sizeof(((thread_arg *)arg)->adr)
	);
	if (ret_val == SOCKET_ERROR) {
		printf("sendto failed with error: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}
	printf("Close thread\n\n");
	closesocket(s);
	return 0;
}

void intHandler(int dummy) {
	printf("Exit by keyboard interrupt\n");
	exit(0);
}

int main() {
	signal(SIGINT, intHandler);
	WSADATA wsaData = { 0 };
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	// Создаём сокет
	int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (s == SOCKET_ERROR) {
		perror("Socket creating error\n");
		return 1;
	};
	printf("Socket successfully created\n");

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	// Устанавливаем порт
	unsigned short port = 0x4444;
	addr.sin_port = htons(port);
	// Слушаем всю сеть 
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	printf("\nSocket family: UDP\n");
	printf("Socket port: %hu\n", port);
	printf("Socket address: %s\n\n", inet_ntoa(addr.sin_addr));

	// Назначаем сокету адрес
	if (bind(s, (SOCKADDR *)&addr, sizeof(addr)) < 0) {
		printf("bind failed with error %d\n", WSAGetLastError());
		return 2;
	};

	printf("Server waiting client packet...\n");
	int rec_data;
	while (1) {
		struct sockaddr_in sender_addr;
		int sender_addr_size = sizeof(sender_addr);
		int ret_val = recvfrom(
			s, 
			(char *)(&rec_data), 
			sizeof(int), 0, 
			(SOCKADDR*)&sender_addr, 
			&sender_addr_size
		);
		if (ret_val == SOCKET_ERROR) {
			wprintf(L"recvfrom failed with error: %d\n", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return 1;
		}
		else {
			thread_arg arg;
			arg.data = rec_data;
			arg.adr = sender_addr;
			HANDLE thread = CreateThread(NULL, 0, send_echo_adr, &arg, 0, NULL);
		};
	};

	return 0;
}