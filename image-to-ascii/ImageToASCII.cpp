//
// Created by AsusTuf on 2024. 01. 08..
//

#include "ImageToASCII.h"

#include <utility>

ImageToASCII::ImageToASCII() = default;

std::string ImageToASCII::getASCIIString(double scaleFactor) {
    return std::string();
}

void ImageToASCII::useReverseCharacters(const bool &reverseColors) {
    if (reverseColors) {
        this->charactersToUse = reversedCharacters;
    } else {
        this->charactersToUse = normalCharacters;
    }
}

void ImageToASCII::setImagePath(const std::string &imagePath) {
    this->imagePath = imagePath;
}

void ImageToASCII::setOutputPath(const std::string &outputPath) {
    this->outputPath = outputPath;
}
