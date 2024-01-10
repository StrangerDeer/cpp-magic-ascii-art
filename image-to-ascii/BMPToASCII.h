//
// Created by AsusTuf on 2024. 01. 08..
//

#pragma once

#include <string>
#include <utility>
#include "ImageToASCII.h"

class BMPToASCII : public ImageToASCII {
public:
    BMPToASCII() : ImageToASCII(){};
    std::string getASCIIString(double scaleFactor = 1.00) override;
};
