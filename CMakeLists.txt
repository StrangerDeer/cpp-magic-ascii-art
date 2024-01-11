cmake_minimum_required(VERSION 3.26)
project(cpp_magic_ascii_art)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(cpp_magic_ascii_art main.cpp
        EasyBMP/EasyBMP.cpp
        EasyBMP/EasyBMP.h
        EasyBMP/EasyBMP_BMP.h
        EasyBMP/EasyBMP_DataStructures.h
        EasyBMP/EasyBMP_VariousBMPutilities.h
        image-to-ascii/ImageToASCII.cpp
        image-to-ascii/ImageToASCII.h
        image-to-ascii/BMPToASCII.cpp
        image-to-ascii/BMPToASCII.h
        image-to-ascii/BMPToASCII.h
        menu/Menu.cpp
        lodepng/lodepng.cpp
        lodepng/lodepng.h
        image-to-ascii/PNGReader.cpp
        image-to-ascii/PNGReader.h)
