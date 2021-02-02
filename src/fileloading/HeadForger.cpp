#include "HeadForger.h"
#define STATUS_LINE "HTTP/1.1 200 OK\r\n"
#define KEEP_ALIVE "Connection: keep-alive\r\n"
#define SERVER_HEADER "Server: Siavash-Win32-Server\r\n"
#define CONTENT_HEADER "Content-Type: text/html\r\n"
#define CONTENT_LENGTH "Content-Length: "
#define EMPTY_LINE "\r\n"
#define MESSAGE_BODY "<html><body><h1>Hello, World!</h1></body></html>"
#define OK_HEAD_HTML "HTTP/1.1 200 OK\r\nServer: Siavash-Win32-Server\r\nContent-Type: text/html\r\n"

my_server::HeadForger::HeadForger() {
	
}

std::string my_server::HeadForger::forgeHead(std::string contentType, int contentLength) {
	std::string strHead = STATUS_LINE;
	strHead.append(KEEP_ALIVE);
	strHead.append("Content-Type: " + contentType + "\r\n");
	strHead.append("Content-Length: " + std::to_string(contentLength) + "\r\n");
	strHead.append(EMPTY_LINE);
	return strHead;
}