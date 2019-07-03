# CMakeList.txt: projekt CMake dla elementu Connections, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory("Sockets")
# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (Connections "Connections.cpp" "Connections.h")

target_link_libraries(Connections PRIVATE Sockets)

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
