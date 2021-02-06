// main.cpp : Defines the entry point for the application.
//

#include "main.h"
using ResponseMapper = my_server::ResponseMapper;
ResponseMapper *ResponseMapper::singleton = NULL;

bool portInRange(int port) {
	return (port >= 1024 && port <= 49151);
}

 int parseArgs(const int &argc,const char**& argv) {
	if (argc != 2) {
		throw "Invalid arguments - too few arguments";
	}

	try {
		int port = std::stoi(argv[1]);
		if (!portInRange(port)) {
			throw "Port out of range - specify a port between 1024-49151";
		} return port;
	}
	catch(const std::exception&) {
		throw "Invalid arguments - format: btcp-http-server.exe <port>(between 1024-49151)";
	}


}

int main(int argc, char* argv[]) {
	int port;
	//make arguments are valid before continuing. 
	try {
		port = parseArgs(argc, (const char**&)argv);
	}
	catch (const char*&errorMsg) {
		std::cerr << "Error:\n" << errorMsg << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "btcp-http-server 1.0\n";
	std::cout << "port: " << port << std::endl;
	ResponseMapper* rm = rm->getInstance();
	my_server::TCPHandler *tcph = new my_server::TCPHandler(port);
	delete tcph;
	return EXIT_SUCCESS;
}
