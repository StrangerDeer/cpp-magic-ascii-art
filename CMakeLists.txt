cmake_minimum_required(VERSION 3.26)
project(cpp_magic_ascii_art)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_magic_ascii_art main.cpp
        EasyBMP/EasyBMP.cpp
        EasyBMP/EasyBMP.h
        EasyBMP/EasyBMP_BMP.h
        EasyBMP/EasyBMP_DataStructures.h
        EasyBMP/EasyBMP_VariousBMPutilities.h)
