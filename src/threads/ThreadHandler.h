#pragma once
#define _WINSOCKAPI_ 
#include<Windows.h>
#include"../network/http/HTTPHandler.h"

namespace my_server {

	class ThreadHandler {
	public:
		ThreadHandler();
		void createThread(void* data);
	};

}