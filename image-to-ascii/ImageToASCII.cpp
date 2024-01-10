//
// Created by AsusTuf on 2024. 01. 08..
//

#include "ImageToASCII.h"

#include <utility>

ImageToASCII::ImageToASCII(const std::string &imagePath, const std::string &outputPath, const bool &reverseColors) {
    this->imagePath = imagePath;
    this->outputPath = outputPath;
    if (reverseColors) {
        this->charactersToUse = reversedCharacters;
    } else {
        this->charactersToUse = normalCharacters;
    }
}

std::string ImageToASCII::getASCIIString(double scaleFactor) {
    return std::string();
}
