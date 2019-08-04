cmake_minimum_required (VERSION 3.10)

add_library(CommonUtils 
	"Printer.h"
    "Printer.cpp"
    )

set_property(TARGET CommonUtils PROPERTY LINKER_LANGUAGE CXX)
set_property(TARGET CommonUtils PROPERTY CXX_STANDARD 17)
