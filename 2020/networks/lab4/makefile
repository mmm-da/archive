all: build-all

build-all: build-tcp

build-tcp: tcp-build-server tcp-build-client

build-udp: udp-build-server udp-build-client

tcp-build-client:
	gcc tcp_client.cpp -o client.exe -lws2_32

tcp-build-server:
	gcc tcp_server.cpp -o server.exe -lws2_32

udp-build-client:
	gcc udp_client.cpp -o client.exe -lws2_32

udp-build-server:
	gcc udp_server.cpp -o server.exe -lws2_32