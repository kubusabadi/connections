
cmake_minimum_required (VERSION 3.10)

add_subdirectory("Sockets")
add_subdirectory("CommonUtils")

add_executable (Connections 
    "Connections.cpp" 
    "Connections.h" 
    "MainWindow.h" 
    "MainWindow.cpp"
    "Modes/TCPReceiving.h"
    "Modes/TCPReceiving.cpp"
    "Modes/TCPSending.h"
    "Modes/TCPSending.cpp"
)

set_property(TARGET Connections PROPERTY CXX_STANDARD 17)

target_link_libraries(Connections Sockets CommonUtils)
target_include_directories(Connections PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/Sockets)
