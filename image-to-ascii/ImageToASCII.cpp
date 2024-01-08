//
// Created by AsusTuf on 2024. 01. 08..
//

#include "ImageToASCII.h"

#include <utility>

std::string ImageToASCII::getASCIIString() {
    return std::string();
}

ImageToASCII::ImageToASCII(const std::string &imagePath, const std::string &outputPath) {
    this->imagePath = imagePath;
    this->outputPath = outputPath;
}
