//
// Created by AsusTuf on 2024. 01. 08..
//

#pragma once


#include <string>

class ImageToASCII {
public:
    ImageToASCII(const std::string &imagePath, const std::string &outputPath);
    virtual std::string getASCIIString();
    std::string characters = " .,:;ox%#@";
    std::string imagePath;
    std::string outputPath;
};
