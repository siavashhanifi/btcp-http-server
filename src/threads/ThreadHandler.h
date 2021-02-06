#pragma once

#include<WinSock2.h>
#include<thread>
#include"../network/http/HTTPHandler.h"

namespace my_server {

	class ThreadHandler {
	public:
		ThreadHandler();
		void createThread(void* data);
	};

}