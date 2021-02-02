#pragma once

#include<vector>
#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include<filesystem>
#include<algorithm>
#include <stdio.h>
#include "HeadForger.h"

namespace my_server {
	using Bytes = std::vector<char>;
	class ResponseMapper {
		static ResponseMapper* singleton;
		public:
			static ResponseMapper* getInstance();
			std::vector<std::string> validRequests;
			std::map<std::string, Bytes> requestedData;
		private:
			ResponseMapper();
	};
}