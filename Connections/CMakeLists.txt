
cmake_minimum_required (VERSION 3.10)

add_subdirectory("OWLConnections")

add_executable (Connections 
    "Connections.cpp" 
    "Connections.h" 
    "MainWindow.h" 
    "MainWindow.cpp"
    "Modes/TCPEchoClient.h"
    "Modes/TCPEchoClient.cpp"
    "Modes/TCPEchoServer.h"
    "Modes/TCPEchoServer.cpp"
    "Modes/TCPReceiving.h"
    "Modes/TCPReceiving.cpp"
    "Modes/TCPSending.h"
    "Modes/TCPSending.cpp"
    "Modes/UDPReceiving.h"
    "Modes/UDPSending.h"
    "Modes/UDPReceiving.cpp"
    "Modes/UDPSending.cpp"
    "Modes/UDPEchoServer.h"
    "Modes/UDPEchoServer.cpp"
    "Modes/UDPEchoClient.h"
    "Modes/UDPEchoClient.cpp"
)


set_property(TARGET Connections PROPERTY CXX_STANDARD 17)

target_link_libraries(Connections OWLConnections CommonUtils)
target_include_directories(Connections PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/OWLConnections)
