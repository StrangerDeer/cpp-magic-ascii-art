//
// Created by AsusTuf on 2024. 01. 08..
//

using namespace std;

#include <fstream>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include "BMPToASCII.h"


std::string BMPToASCII::getASCIIString() {
    std::ifstream imageFile(imagePath, std::ios::binary);

    if (!imageFile.is_open()) {
        std::cerr << "Error opening image file" << std::endl;
    }

    // Get image dimensions
    imageFile.seekg(18, std::ios::beg);
    int width, height;
    imageFile.read(reinterpret_cast<char*>(&width), sizeof(int));
    imageFile.read(reinterpret_cast<char*>(&height), sizeof(int));

    // Check if the image dimensions are valid
    if (width <= 0 || height <= 0) {
        std::cerr << "Invalid image dimensions" << std::endl;
        imageFile.close();
    }

    // Calculate row size, including padding
    int rowSize = ((width * 3 + 3) / 4) * 4;

    // Skip to image data
    imageFile.seekg(54, std::ios::beg);

    // Read image data
    uint8_t pixel[3];
    std::string result = "";
    std::string endl;
    endl = char(13);
    endl += char(10);
    for (int y = 0; y < height; y++) {
        std::string row = "";
        for (int x = 0; x < width; x++) {
            if (!imageFile.read(reinterpret_cast<char*>(pixel), 3)) {
                std::cerr << "Error reading image data" << std::endl;
                imageFile.close();
            }

            int i = pixel[0] + pixel[1] + pixel[2];
            i = (i * characters.length()) / 768;
            row += characters[characters.length() -1 - i];
        }

        // Skip over padding
        imageFile.seekg(rowSize - 3 * width, std::ios::cur);
        std::reverse(row.begin(), row.end());
        result += row;
        result += endl;
    }
    reverse(result.begin(), result.end());

    imageFile.close();

    // Save result to text file
    std::ofstream outputFile(outputPath);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file" << std::endl;
    }

    outputFile << result;
    outputFile.close();

    return result;
}
