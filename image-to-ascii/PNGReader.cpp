//
// Created by Deer on 10/01/2024.
//

#include "PNGReader.h"

void PNGReader::loadPicture(double scaleFactor) {
    bool ignore_checksums = false;
    std::vector<unsigned char> buffer;

    unsigned originalWidth, originalHeight;

    lodepng::load_file(buffer, imagePath); //load the image file with given filename

    lodepng::State state;

    if(ignore_checksums) {
        state.decoder.ignore_crc = 1;
        state.decoder.zlibsettings.ignore_adler32 = 1;
    }

    unsigned error = lodepng::decode(image, originalWidth, originalHeight, state, buffer);

    if(error) {
        std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }

    unsigned scaledWidth = static_cast<unsigned>(originalWidth * scaleFactor);
    unsigned scaledHeight = static_cast<unsigned>(originalHeight * scaleFactor);

    std::vector<unsigned char> scaledImage(scaledWidth * scaledHeight * 4, 255);

    for (unsigned y = 0; y < scaledHeight; ++y) {
        for (unsigned x = 0; x < scaledWidth; ++x) {
            unsigned originalX = static_cast<unsigned>(x / scaleFactor);
            unsigned originalY = static_cast<unsigned>(y / scaleFactor);

            for (unsigned c = 0; c < 4; ++c) {
                scaledImage[(y * scaledWidth + x) * 4 + c] = image[(originalY * originalWidth + originalX) * 4 + c];
            }
        }
    }

    image = scaledImage;

    width = static_cast<int>(scaledWidth);
    height = static_cast<int>(scaledHeight);

}

void PNGReader::createASCIIString(double scaleFactor) {

    for(int i = 0; i < image.size(); i += 4){

        char result;

        int red = (int)image[i];
        int green = (int)image[i+1];
        int blue = (int)image[i+2];

        int value = static_cast<int>(0.3 * red + 0.59 * green + 0.11 * blue);
        value = (value * charactersToUse.length()) / 256;
        result = charactersToUse[charactersToUse.length() - 1 - value];
        asciiChars.push_back(result);

    }
}

std::string PNGReader::getASCIIString(double scaleFactor) {
    loadPicture(scaleFactor);
    createASCIIString(scaleFactor);

    std::string result = "";

    for(int i = 0; i < height; i += 3){
        for(int j = 0; j < width; j++){
            result += asciiChars[i * width + j];
        }
        result += "\n";
    }

    std::ofstream outputFile(outputPath);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file" << std::endl;
    }

    outputFile << result;
    outputFile.close();

    return result;
}
