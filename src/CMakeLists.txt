# CMakeList.txt : CMake project for my-server, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("btcp-http-server")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "main.cpp"
 "main.h"
 "network/tcp/TCPHandler.cpp"
 "network/http/HTTPHandler.cpp"
 "network/tcp/TCPHandler.h"
 "network/http/HTTPHandler.h"
 "threads/ThreadHandler.cpp"
 "threads/ThreadHandler.h"
 "fileloading/HeadForger.cpp"
 "fileloading/ResponseMapper.cpp"
 "fileloading/ResponseMapper.h"
 "fileloading/HeadForger.h")

# Required for usage of Window Sockets 2 library.
if(WIN32)
  target_link_libraries(${PROJECT_NAME} ws2_32)
endif()

# Required for usage of std::filesystem in ResponseMapper
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Copies files from src/www to <build location>/www
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/www 
                   $<TARGET_FILE_DIR:${PROJECT_NAME}>/www/)