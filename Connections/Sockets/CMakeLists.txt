cmake_minimum_required (VERSION 3.10)

add_library(Sockets 
	"WinsockWrapper.h" 
	"WinsockWrapper.cpp" 
	)

set_property(TARGET Sockets PROPERTY CXX_STANDARD 17)

if (WIN32)
    add_subdirectory("Winsock")
	target_link_libraries(Sockets wsock32 ws2_32 Winsock)
	
endif()