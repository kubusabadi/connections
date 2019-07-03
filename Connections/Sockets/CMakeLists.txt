cmake_minimum_required (VERSION 3.8)

add_library(Sockets 
	"TCPConnection.h" 
	"TCPConnection.cpp" 
	"Socket.h" 
	"SocketFactory.h"
	)

if (WIN32)
    add_subdirectory("Winsock")
	target_link_libraries(Sockets wsock32 ws2_32 Winsock)
endif()