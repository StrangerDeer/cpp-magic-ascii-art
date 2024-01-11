//
// Created by AsusTuf on 2024. 01. 09..
//

#pragma once

#include <string>
#include <vector>
#include <map>
#include "../image-to-ascii/ImageToASCII.h"
#include "../image-to-ascii/PNGReader.h"
#include "../image-to-ascii/BMPToASCII.h"

class Menu {
public:
    Menu();
    void run();

private:
    std::vector<std::string> fileFormats = {"bmp", "png"};
    std::vector<std::string> imageNames;
    std::vector<std::string> bmpImages = {"thumbs_up", "person_with_candle", "antilope"};
    std::vector<std::string> pngImages = {"thumbs_up", "person_with_candle", "boing", "szemuveges_no", "cica", "bob_ross", "solaire"};
    std::vector<std::string> scaleFactors = {"extra large", "large", "normal", "small", "extra small"};

    void displayImageNames();
    void chooseImageName(const int &input);
    void displayFileFormats();
    void chooseFileFormat(const int &input);
    void getImagePath();
    void chooseOutputName();
    void displayScaleFactors();
    void chooseScaleFactor(const int &input);
    void displayColorReversion();
    void chooseColorReversion(const int &input);
    void displayImageDisplay();
    void chooseIfImageWillBeDisplayed(const int &input);

    void displayContinue();
    void chooseContinue(const int &input);

    static bool isInputCorrect(int input, int maxInput);

    void processImage();

    std::string chosenFileName;
    std::string chosenFileFormat;
    std::string imageFilePath;
    std::string outputPath;

    double imageScaleFactor;
    bool isColorReversed;
    bool isImageDisplayed;

    ImageToASCII* converter;
    PNGReader pngReader;
    BMPToASCII bmpToAscii;


    bool isRunning;
};
