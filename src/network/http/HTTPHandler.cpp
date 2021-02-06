#include"HTTPHandler.h"

std::string my_server::HTTPHandler::filterRequest(char* request) {
	std::string filteredRequest;
	for (int i = 4; i < recieveBufferSize; i++) {
		if (request[i] == ' ')
			break;
		filteredRequest += request[i];
	}
	return filteredRequest;
}

my_server::HTTPHandler::HTTPHandler(SOCKET client) {
	clientSocket = client;
	responseMapper = responseMapper->getInstance();
	recieveBufferSize = 5 + responseMapper->getLongestPath();
	handleRequest();
}

void my_server::HTTPHandler::handleRequest() {
	using Bytes = std::vector<char>;
	char *recieveBuffer = new char[recieveBufferSize];
	while (true) {

		//blocking get 512 bytes from the client.
		int result = recv(clientSocket, recieveBuffer, (int)recieveBufferSize, 0);

		//socket alive?
		if (result == 0 || result == SOCKET_ERROR)
			break;

		//filter out the path from the http get request.
		std::string filteredReq = filterRequest(recieveBuffer);

		//get bytes for the request.
		Bytes bytes;
		try {
			 bytes = responseMapper->requestedData.at(filteredReq);
		}
		catch (std::out_of_range) {//unmapped requests redirect to index.html 
			bytes = responseMapper->requestedData.at("/");
		}
		//send bytes via through client socket.
		send(clientSocket, bytes.data(), (int)bytes.size(), 0);
	}
	delete[] recieveBuffer;
}