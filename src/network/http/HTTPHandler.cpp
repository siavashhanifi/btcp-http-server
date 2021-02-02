#include"HTTPHandler.h"

std::string filterRequest(char* request) {
	std::string filteredRequest = "";
	int i = 4;
	while (true) {
		if (request[i] == ' ' || i > 512)
			break;
		filteredRequest += request[i];
		i++;
	}
	return filteredRequest;
}

my_server::HTTPHandler::HTTPHandler(SOCKET client) {
	clientSocket = client;
	responseMapper = responseMapper->getInstance();
	handleRequest();
}

void my_server::HTTPHandler::handleRequest() {
	char recievedBuffer[512] = {};
	int result;
	std::string filteredReq;
	std::vector<char> bytes;
	while (true) {
		result = recv(clientSocket, recievedBuffer, 512, 0);
		if (result == 0 || result == SOCKET_ERROR)
			break;
		filteredReq = filterRequest(recievedBuffer);
		bytes = responseMapper->requestedData[filteredReq];
		size_t sentbytes = send(clientSocket, bytes.data(), bytes.size(), 0);
	}
}

void my_server::HTTPHandler::sendAllBytes(std::vector<char> bytes) {
	char* bytesPtr = bytes.data();
	size_t nOBytes = bytes.size();
	size_t sentBytes = 0;
	while (nOBytes != 0) {
		sentBytes = send(clientSocket, bytesPtr, nOBytes, 0);
		nOBytes -= sentBytes;//{sent,sent,sent, nots,nots, nots}
		bytesPtr += sentBytes;
	}
	std::cout << "sent " << nOBytes << "bytes successfully" << std::endl;
}