#include "HeadForger.h"
#define RESPONSE_200 "HTTP/1.1 200 OK\r\n"
#define KEEP_ALIVE "Connection: keep-alive\r\n"
#define SERVER_HEADER "Server: siavash-ws2_32-server\r\n"
#define EMPTY_LINE "\r\n"

std::string my_server::forgeHead(std::string contentType, uintmax_t contentLength) {
	std::string strHead = RESPONSE_200;
	strHead.append(KEEP_ALIVE);
	strHead.append("Content-Type: " + contentType + "\r\n");
	strHead.append("Content-Length: " + std::to_string(contentLength) + "\r\n");
	strHead.append(SERVER_HEADER);
	strHead.append(EMPTY_LINE);
	return strHead;
}
