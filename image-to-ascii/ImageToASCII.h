//
// Created by AsusTuf on 2024. 01. 08..
//

#pragma once


#include <string>

class ImageToASCII {
public:
    ImageToASCII(const std::string &imagePath, const std::string &outputPath, const bool &reverseColors);
    virtual std::string getASCIIString(double scaleFactor = 1.00);
protected:
    std::string charactersToUse = "";
    std::string normalCharacters = " .,:;ox%#@";
    std::string reversedCharacters = "@#%xo;:,. ";
    std::string imagePath;
    std::string outputPath;
};
