#pragma once

#include<string>
#include<iostream>
#include <WinSock2.h>
#include"../../threads/ThreadHandler.h"


namespace my_server {

	class TCPHandler {
	public:
		TCPHandler(u_short port);
	private:
		SOCKET serverSocket;
		sockaddr_in socketDetails;
		my_server::ThreadHandler *threadHandler;
		void createSocket();
		void bindSocket();
		void handleClients();
	};
}