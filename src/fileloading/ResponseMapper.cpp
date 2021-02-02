#include"ResponseMapper.h"
#define ROOT_DIR "www"

namespace fs = std::filesystem;
using string = std::string;

my_server::ResponseMapper* my_server::ResponseMapper::getInstance() {
    if (singleton == NULL)
        singleton = new ResponseMapper();
    return singleton;
}


my_server::ResponseMapper::ResponseMapper() {
    HeadForger headForger;
    std::cout << "Loading website files..." << ROOT_DIR << std::endl;
    for (const auto& entry : fs::recursive_directory_iterator(ROOT_DIR)) {

        auto path = entry.path();
        string pathStr = path.string();

        //remove ROOT_DIR from beginning of pathStr
        string fileLoc = pathStr.erase(0, std::strlen(ROOT_DIR) + 1);
        fileLoc.insert(0, "/");

        string contentType = "";
        //string keepAlive = "";
        string extension = path.extension().string();
        if (extension.compare(".html") == 0)
            contentType = "text/html";
        else if (extension.compare(".js") == 0)
            contentType = "text/javascript";
        else if (extension.compare(".css") == 0)
            contentType = "text/css";
        else if (extension.compare(".jpeg") == 0 || extension.compare(".jpg") == 0)
            contentType = "image/jpeg";
        else if (extension.compare(".png") == 0)
            contentType = "image/jpeg";
        else contentType = "text/html";
        
        //add http head to  response
        string httpHead = headForger.forgeHead(contentType, entry.file_size());
        std::vector<char> response(httpHead.begin(), httpHead.end());

        //read bytes from file
        std::ifstream input(path, std::ios::binary);
        std::vector<char> bytes(
            (std::istreambuf_iterator<char>(input)),
            (std::istreambuf_iterator<char>()));
        input.close();

        //add message-content to response
        response.insert(std::end(response), std::begin(bytes), std::end(bytes));

        //change windows style path to unix style \ -> /
        int i = 0;
        for (char c : fileLoc) {
            if (c == '\\')
                fileLoc[i] = '/';
            i++;
         }

        validRequests.push_back(fileLoc);
        requestedData[fileLoc] = response;
    }
    requestedData["/"] = requestedData["/index.html"];
    std::cout << "All files successfully loaded!" << std::endl;
}
