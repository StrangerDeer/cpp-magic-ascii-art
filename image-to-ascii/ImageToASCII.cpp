//
// Created by AsusTuf on 2024. 01. 08..
//

#include "ImageToASCII.h"

#include <utility>

ImageToASCII::ImageToASCII(const std::string &imagePath, const std::string &outputPath) {
    this->imagePath = imagePath;
    this->outputPath = outputPath;
}

std::string ImageToASCII::getASCIIString(double scaleFactor) {
    return std::string();
}

