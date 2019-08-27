
cmake_minimum_required (VERSION 3.10)

add_library(Winsock 
    "Error.h"
    "Error.cpp"
    "WinsockSocket.h"
    "WinsockSocket.cpp"
    "WinsockSocketBuilder.h"
    "WinsockSocketBuilder.cpp"
    "WinsockSocketServer.h" 
	"WinsockSocketServer.cpp" 
    "WinsockSocketServerTCP.h" 
	"WinsockSocketServerTCP.cpp"
    "WinsockSocketServerUDP.h" 
	"WinsockSocketServerUDP.cpp" 
    "WinsockSocketClient.h" 
	"WinsockSocketClient.cpp" 
)

set_property(TARGET Winsock PROPERTY CXX_STANDARD 17)

target_link_libraries(Winsock wsock32 ws2_32 CommonUtils)
target_include_directories(Winsock PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/../../CommonUtils)
