#include "ThreadHandler.h"

my_server::ThreadHandler::ThreadHandler() {
	
}
	

DWORD WINAPI createHTTPHandler(LPVOID lpParam) {
	SOCKET client = (SOCKET)lpParam;
	my_server::HTTPHandler *httpHandler = new my_server::HTTPHandler(client);
	delete httpHandler;
	return 0;
}

void my_server::ThreadHandler::createThread(void *data) {
	CreateThread(NULL,
		0, createHTTPHandler, data,
		0, NULL);
}

