#include "TCPHandler.h"

my_server::TCPHandler::TCPHandler(u_short port) {
	threadHandler = new ThreadHandler();
	createSocket();
	bindSocket();
	handleClients();
}

void my_server::TCPHandler::createSocket() {
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != NO_ERROR)
		std::cerr << "Error at WSAStartup()" << std::endl;

	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
		std::cerr << "Invalid server socket" << std::endl;
}

void my_server::TCPHandler::bindSocket() {
	socketDetails.sin_family = AF_INET;
	socketDetails.sin_addr.s_addr = inet_addr("127.0.0.1");
	socketDetails.sin_port = htons(27015);
	int result = bind(serverSocket, (SOCKADDR*)&socketDetails, sizeof(sockaddr_in));
	if (result != 0)
		std::cerr << "Bind failed" << std::endl;
}

void my_server::TCPHandler::handleClients() {
	listen(serverSocket, 3);
	while (true) {
		SOCKET client = accept(serverSocket, NULL, NULL);
		if (client == INVALID_SOCKET)
			std::cerr << "Invalid client socket" << std::endl;
		threadHandler->createThread((void*)client);
	}
}