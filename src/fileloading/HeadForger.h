#include <string>

namespace my_server {
	class HeadForger {
	public:
		HeadForger();
		using string = std::string;
		string strHead;
		string contentType;
		string contentLength;
		string forgeHead(string contentType, int contentLength);
	};
}
