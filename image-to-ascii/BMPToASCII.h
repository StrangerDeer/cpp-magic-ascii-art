//
// Created by AsusTuf on 2024. 01. 08..
//

#pragma once

#include <string>
#include <utility>
#include "ImageToASCII.h"

class BMPToASCII : public ImageToASCII {
public:
    BMPToASCII(const std::string &imagePath, const std::string &outputPath, const bool &reverseColors) : ImageToASCII(imagePath, outputPath, reverseColors){};
    std::string getASCIIString(double scaleFactor = 1.00) override;
};
