#include "ThreadUtility.h"

void *my_server::createHTTPHandler(void *param) {
	SOCKET client = (SOCKET)param;
	auto httpHandler = new my_server::HTTPHandler(client);
	delete httpHandler;
	return 0;
}

void my_server::createThread(void *data) {
	using thread = std::thread;
	thread newThread = thread(&createHTTPHandler, data);
	//let the thread run freely/detached from the main thread.
	newThread.detach();
}

