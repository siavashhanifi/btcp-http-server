#include "TCPHandler.h"

my_server::TCPHandler::TCPHandler(u_short port) {
	threadHandler = new ThreadHandler();
	createSocket();
	bindSocket(port);
	handleClients();
}

void my_server::TCPHandler::createSocket() {
	WSADATA wsaData;
	//required before using sockets on windows.
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != NO_ERROR)
		std::cerr << "Error at WSAStartup();"<< WSAGetLastError() << std::endl;
	//create a socket to listen for new clients on.
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
		std::cerr << "Invalid server socket" << std::endl;
}

void my_server::TCPHandler::bindSocket(u_short port) {
	//set socket details ie. specify protocols, ip-addresses and port to use.
	socketDetails.sin_family = AF_INET;
	//binds socket to listen at any interface (all interfaces?).
	socketDetails.sin_addr.s_addr = INADDR_ANY;
	socketDetails.sin_port = htons(port);
	int result = bind(serverSocket, (SOCKADDR*)&socketDetails, sizeof(sockaddr_in));
	if (result != 0)
		std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
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