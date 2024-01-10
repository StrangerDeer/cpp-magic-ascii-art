//
// Created by AsusTuf on 2024. 01. 09..
//

#pragma once

#include <string>
#include <vector>
#include <map>
#include "../image-to-ascii/ImageToASCII.h"

class Menu {
public:
    Menu();
    void run();

private:
    std::vector<std::string> fileFormats = {"bmp", "png", "jpg"};
    std::vector<std::string> imageNames = {"thumbs_up", "person_with_candle"};
    std::vector<std::string> scaleFactors = {"large", "normal", "small", "extra small"};

    void displayImageNames();
    void chooseImageName(const int &input);
    void displayFileFormats();
    void chooseFileFormat(const int &input);
    void chooseOutputName();
    void displayScaleFactors();
    void chooseScaleFactor(const int &input);
    void displayColorReversion();
    void chooseColorReversion(const int &input);
    void displayImageDisplay();
    void chooseIfImageWillBeDisplayed(const int &input);

    static bool isInputCorrect(int input, int maxInput);

    void processImage();

    void getImagePath();

    std::string chosenFileName;
    std::string chosenFileFormat;
    std::string imageFilePath;
    std::string outputPath;

    double imageScaleFactor;
    bool isColorReversed;
    bool isImageDisplayed;

    ImageToASCII* converter;

    bool isRunning;
};
