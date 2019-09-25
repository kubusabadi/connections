# CMakeList.txt: plik projektu CMake najwyższego poziomu, wykonaj konfigurację globalną
# i uwzględnij podprojekty w tym miejscu.
#
cmake_minimum_required (VERSION 3.10)

project ("Connections")

# Uwzględnij podprojekty.
add_subdirectory ("Connections")
