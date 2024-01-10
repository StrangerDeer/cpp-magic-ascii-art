//
// Created by Deer on 10/01/2024.
//

#ifndef CPP_MAGIC_ASCII_ART_PNGREADER_H
#define CPP_MAGIC_ASCII_ART_PNGREADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "lodepng/lodepng.h"

class PNGReader {

public:
    PNGReader(std::string& filename, std::string out) : filename(filename), outputPath(out) {};
    void loadPicture();
    void printPicture();

private:
    int height{0};
    std::string filename;
    std::string outputPath;
    std::vector<char> asciiChars;
    std::vector<unsigned char> image;
    int width{0};
    void createASCIIString();

};


#endif //CPP_MAGIC_ASCII_ART_PNGREADER_H
