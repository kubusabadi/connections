
cmake_minimum_required (VERSION 3.10)

add_library(Winsock 
	"WinsockSocket.h" 
	"WinsockSocket.cpp" 
    "Error.h"
    "Error.cpp"
)

set_property(TARGET Winsock PROPERTY CXX_STANDARD 17)

target_link_libraries(Winsock wsock32 ws2_32 CommonUtils)