#pragma once

#include<iostream>
#include<string>
#include<vector>
#include <WinSock2.h>
#include "../../fileloading/ResponseMapper.h"

namespace my_server {

	class HTTPHandler {
	public:
		HTTPHandler(SOCKET client);
	private:
		SOCKET clientSocket;
		size_t recieveBufferSize;
		my_server::ResponseMapper *responseMapper;
		std::string filterRequest(char *request);
		void handleRequest();
	};
}