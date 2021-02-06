#include "ThreadHandler.h"

my_server::ThreadHandler::ThreadHandler() {
	
}
	
void *createHTTPHandler(void *param) {
	SOCKET client = (SOCKET)param;
	auto httpHandler = new my_server::HTTPHandler(client);
	delete httpHandler;
	return 0;
}

void my_server::ThreadHandler::createThread(void *data) {
	using thread = std::thread;
	thread newThread = thread(&createHTTPHandler, data);
	//let the thread run freely/detached from the main thread.
	newThread.detach();
}

