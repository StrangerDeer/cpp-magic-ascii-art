//
// Created by AsusTuf on 2024. 01. 08..
//

#pragma once


#include <string>

class ImageToASCII {
public:
    ImageToASCII();
    virtual std::string getASCIIString(double scaleFactor = 1.00);
    void useReverseCharacters(const bool &reverseColors);
    void setImagePath(const std::string &imagePath);
    void setOutputPath(const std::string &outputPath);
protected:
    std::string charactersToUse = "";
    std::string normalCharacters = " .,:;ox%#@";
    std::string reversedCharacters = "@#%xo;:,. ";
    std::string imagePath;
    std::string outputPath;
};
