//
// Created by Deer on 10/01/2024.
//

#ifndef CPP_MAGIC_ASCII_ART_PNGREADER_H
#define CPP_MAGIC_ASCII_ART_PNGREADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ImageToASCII.h"
#include "../lodepng/lodepng.h"

class PNGReader : public ImageToASCII {

public:
    PNGReader() : ImageToASCII(){};
    void loadPicture(double scaleFactor);
    std::string getASCIIString(double scaleFactor = 1.00) override;

private:
    int height{0};
    std::vector<char> asciiChars;
    std::vector<unsigned char> image;
    int width{0};
    void createASCIIString(double scaleFactor);

};


#endif //CPP_MAGIC_ASCII_ART_PNGREADER_H
