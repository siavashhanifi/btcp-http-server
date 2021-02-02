// main.cpp : Defines the entry point for the application.
//

#include "main.h"
using ResponseMapper = my_server::ResponseMapper;
ResponseMapper *ResponseMapper::singleton = NULL;

int main(){
	std::cout << "btcp-http-server 1.0" << std::endl;
	ResponseMapper* rm = rm->getInstance();
	my_server::TCPHandler *tcph = new my_server::TCPHandler(27015);
	return 0;
}
