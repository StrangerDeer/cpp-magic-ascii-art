//
// Created by Deer on 10/01/2024.
//

#include "PNGReader.h"

void PNGReader::loadPicture() {
    bool ignore_checksums = false;
    std::vector<unsigned char> buffer;

    unsigned w, h;

    lodepng::load_file(buffer, filename); //load the image file with given filename

    lodepng::State state;

    if(ignore_checksums) {
        state.decoder.ignore_crc = 1;
        state.decoder.zlibsettings.ignore_adler32 = 1;
    }

    unsigned error = lodepng::decode(image, w, h, state, buffer);

    if(error) {
        std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }

    std::cout << "Filesize: " << buffer.size() << " (" << buffer.size() / 1024 << "K)" << std::endl;
    std::cout << "Width: " << w << std::endl;
    std::cout << "Height: " << h << std::endl;
    std::cout << "Num pixels: " << w * h << std::endl;

    width = (int)w;
    height = (int)h;

    if(w > 0 && h > 0) {
        std::cout << "Top left pixel color:"
                  << " r: " << (int)image[0]
                  << " g: " << (int)image[1]
                  << " b: " << (int)image[2]
                  << " a: " << (int)image[3]
                  << std::endl;
    }
}

void PNGReader::createASCIIString() {

    std::string charactersToUse = " .,:;ox%#@";

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

void PNGReader::printPicture() {
    createASCIIString();

    std::cout << "Length: " << std::to_string(asciiChars.size()) << std::endl;
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
}
