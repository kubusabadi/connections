
cmake_minimum_required (VERSION 3.10)

add_subdirectory("Sockets")

add_executable (Connections 
    "Connections.cpp" 
    "Connections.h" 
    "MainWindow.h" 
    "MainWindow.cpp"
)

set_property(TARGET Connections PROPERTY CXX_STANDARD 17)

target_link_libraries(Connections PRIVATE Sockets)
