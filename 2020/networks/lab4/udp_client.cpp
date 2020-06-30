#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <winsock.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <ctime>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

void intHandler(int dummy) {
	printf("Exit by keyboard interrupt\n");
	exit(0);
}

int main() {
	signal(SIGINT, intHandler);

	time_t t;
	srand((unsigned)time(&t));
	int data = rand();

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
	// Задаем порт
	unsigned short port = 0x4444;
	addr.sin_port = htons(port);
	// Задаем адрес сервера
	char address[] = "127.0.0.1";

	addr.sin_addr.s_addr = inet_addr(address);

	printf("\nSocket family: UDP\n");
	printf("Socket port: %hu\n", port);
	printf("Socket address: %s\n\n", address);

	printf("Press Enter to start transsmition...\n");
	getchar();
	getchar();
	printf("Sending identification packet to server\n");
	printf("Sending number: %d\n", data);
	int ret_val = sendto(
		s, 
		(char *)(&data), 
		sizeof(int), 0, 
		(SOCKADDR *)& addr, 
		sizeof(addr));
	if (ret_val == SOCKET_ERROR) {
		printf("\nsendto failed with error: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}
	printf("Await echo packet\n");
	int echo_data;
	struct sockaddr_in sender_addr;
	int sender_addr_size = sizeof(sender_addr);

	ret_val = recvfrom(
		s, 
		(char *)(&echo_data), 
		sizeof(int), 0, 
		(SOCKADDR*)&sender_addr, 
		&sender_addr_size
	);
	if (ret_val == SOCKET_ERROR) {
		printf("\nrecvfrom failed with error: %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	};
	printf("Echo number: %d\n", echo_data);
	return 0;
}