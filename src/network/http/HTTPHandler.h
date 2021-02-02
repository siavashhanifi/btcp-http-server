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
		my_server::ResponseMapper *responseMapper;
		void handleRequest();
		void sendAllBytes(std::vector<char> bytes);
	};
}