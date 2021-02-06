#pragma once

#include<WinSock2.h>
#include<thread>
#include"../network/http/HTTPHandler.h"

namespace my_server {
	void* createHTTPHandler(void* param);
	void createThread(void* data);
}