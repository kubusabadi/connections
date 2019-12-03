cmake_minimum_required (VERSION 3.10)

add_library(OWLConnections 
    "Socket.h"
    "SocketBuilder.h"
    "SocketBuilder.cpp"
)

set_property(TARGET OWLConnections PROPERTY CXX_STANDARD 17)

add_subdirectory("CommonUtils")

if (WIN32)
    add_subdirectory("Winsock")
    target_link_libraries(OWLConnections wsock32 ws2_32 Winsock)
endif()