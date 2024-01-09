//
// Created by AsusTuf on 2024. 01. 08..
//

#pragma once

#include <string>
#include <utility>
#include "ImageToASCII.h"

class BMPToASCII : public ImageToASCII {
public:
    BMPToASCII(const std::string &imagePath, const std::string &outputPath) : ImageToASCII(imagePath, outputPath){};
    std::string getASCIIString(double scaleFactor = 1.00, bool terminalChars = false) override;
};
