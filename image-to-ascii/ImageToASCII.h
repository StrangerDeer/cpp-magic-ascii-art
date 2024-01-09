//
// Created by AsusTuf on 2024. 01. 08..
//

#pragma once


#include <string>

class ImageToASCII {
public:
    ImageToASCII(const std::string &imagePath, const std::string &outputPath);
    virtual std::string getASCIIString(double scaleFactor = 1.00, bool terminalChars = false);
protected:
    std::string characters = " .,:;ox%#@";
    std::string terminalCharacters = "@#%xo;:,. ";
    std::string imagePath;
    std::string outputPath;
};
