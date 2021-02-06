#include"ResponseMapper.h"
#define ROOT_DIR "www"

namespace fs = std::filesystem;
using string = std::string;

//Read about the singleton pattern to understand this better.
my_server::ResponseMapper* my_server::ResponseMapper::getInstance() {
    if (singleton == NULL)
        singleton = new ResponseMapper();
    return singleton;
}

//Decides the content-type for an HTTP head, based on a file extension.
//param fExt: file extension
string getContentType(const string& fExt) {
    string contentType = "";
    if (fExt.compare(".html") == 0)
        contentType = "text/html";
    else if (fExt.compare(".js") == 0)
        contentType = "text/javascript";
    else if (fExt.compare(".css") == 0)
        contentType = "text/css";
    else if (fExt.compare(".jpeg") == 0 || fExt.compare(".jpg") == 0)
        contentType = "image/jpeg";
    else if (fExt.compare(".png") == 0)
        contentType = "image/jpeg";
    else contentType = "text/html";
    return contentType;
}

//Loads files from ROOT_DIR: Maps their path i.e "/index.html" to a vector of bytes(chars). 
my_server::ResponseMapper::ResponseMapper() {
    longestPath = 0;
    std::cout << "Loading website files..." << ROOT_DIR << std::endl;
    for (const auto& entry : fs::recursive_directory_iterator(ROOT_DIR)) {

        auto path = entry.path();
        string pathStr = path.string();

        //remove ROOT_DIR from beginning of pathStr.
        string filePath = pathStr.erase(0, std::strlen(ROOT_DIR) + 1);
        filePath.insert(0, "/");

        //get contentType for HTTP head based on file extension.
        string contentType = getContentType(path.extension().string());
        
        //Generate HTTP head for file.
        string httpHead = my_server::forgeHead(contentType, entry.file_size());

        //add HTTP head to response.
        std::vector<char> response(httpHead.begin(), httpHead.end());

        //read bytes(HTTP message-content) from file.
        std::ifstream input(path, std::ios::binary);
        std::vector<char> bytes(
            (std::istreambuf_iterator<char>(input)),
            (std::istreambuf_iterator<char>()));
        input.close();

        //add HTTP message-content to response.
        response.insert(std::end(response), std::begin(bytes), std::end(bytes));

        //change windows style path to unix style \ -> /
        int i = 0;
        for (char c : filePath) {
            if (c == '\\')
                filePath[i] = '/';
            i++;
         }

        if (filePath.length() > longestPath)
           longestPath = filePath.length();

        validRequests.push_back(filePath);
        requestedData[filePath] = response;
    }
    requestedData["/"] = requestedData["/index.html"];
    std::cout << "All files successfully loaded!" << std::endl;
}

size_t my_server::ResponseMapper::getLongestPath() {
    return this->longestPath;
}