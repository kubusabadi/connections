
cmake_minimum_required (VERSION 3.8)

add_library(Winsock 
	"WinsockSocket.h" 
	"WinsockSocket.cpp" 
)

target_link_libraries(Winsock wsock32 ws2_32)