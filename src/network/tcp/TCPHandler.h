#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include<string>
#include<iostream>

#include"../../threads/ThreadUtility.h"



namespace my_server {

	class TCPHandler {
	public:
		TCPHandler(u_short port);
	private:
		SOCKET serverSocket;
		sockaddr_in socketDetails;
		void createSocket();
		void bindSocket(u_short port);
		void handleClients();
	};
}