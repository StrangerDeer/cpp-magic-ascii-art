//
// Created by AsusTuf on 2024. 01. 09..
//

#include <iostream>
#include "Menu.h"
#include "../image-to-ascii/BMPToASCII.h"
#include "../image-to-ascii/PNGReader.h"

Menu::Menu() {
    isRunning = true;
    bmpToAscii = BMPToASCII();
    pngReader = PNGReader();
}

void Menu::run() {
    while (isRunning) {
        std::cout << "Please choose an image format!" << std::endl;
        displayFileFormats();
        displayImageNames();
        getImagePath();
        chooseOutputName();
        displayScaleFactors();
        displayColorReversion();
        displayImageDisplay();
        processImage();
        displayContinue();
    }
}

void Menu::displayImageNames() {
    int input;
    int index = 1;
    for (std::string imageName : imageNames) {
        std::cout << "   " + std::to_string(index) + " - " + imageName << std::endl;
        index++;
    }
    std::cin >> input;
    if (isInputCorrect(input, imageNames.size())) {
        chooseImageName(input);
    } else {
        displayImageNames();
    }
}

void Menu::chooseImageName(const int &input) {
    chosenFileName = imageNames.at(input-1);
}

void Menu::displayFileFormats() {
    int input;
    int index = 1;
    for (std::string format : fileFormats) {
        std::cout << "   " + std::to_string(index) + " - " + format << std::endl;
        index++;
    }
    std::cin >> input;
    if (isInputCorrect(input, fileFormats.size())) {
        chooseFileFormat(input);
    } else {
        displayFileFormats();
    }
}

void Menu::chooseFileFormat(const int &input) {
    switch (input) {
        case 1: {
            chosenFileFormat = "bmp";
            imageNames = bmpImages;
            converter = &bmpToAscii;
            break;
        }
        case 2: {
            chosenFileFormat = "png";
            imageNames = pngImages;
            converter = &pngReader;
            break;
        }
        default: {
            std::cerr << "Something went wrong";
            displayFileFormats();
        }
    }

}

void Menu::getImagePath() {
    imageFilePath = "../pics/" + chosenFileName + "." + chosenFileFormat;
    converter->setImagePath(imageFilePath);
}

void Menu::chooseOutputName() {
    std::string outputName;
    std::cout << "Choose a name for the new txt file!" << std::endl;
    std::cin >> outputName;
    outputPath = "../pics/out/" + outputName + ".txt";
    converter->setOutputPath(outputPath);
}

bool Menu::isInputCorrect(int input, int maxInput) {
    if (input <= 0 || input > maxInput) {
        return false;
    }
    return true;
}

void Menu::displayScaleFactors() {
    int input;
    int index = 1;
    std::map<std::string, double>::iterator it;
    std::cout << "Choose a scale for the ASCII!" << std::endl;
    for (std::string scale : scaleFactors) {
        std::cout << "   " + std::to_string(index) + " - " + scale << std::endl;
        index++;
    }
    std::cin >> input;
    if (isInputCorrect(input, scaleFactors.size())) {
        chooseScaleFactor(input);
    } else {
        displayScaleFactors();
    }
}

void Menu::chooseScaleFactor(const int &input) {
    switch (input) {
        case 1: {
            imageScaleFactor = 1.25;
            break;
        }
        case 2: {
            imageScaleFactor = 1;
            break;
        }
        case 3: {
            imageScaleFactor = 0.75;
            break;
        }
        case 4: {
            imageScaleFactor = 0.5;
            break;
        }
        case 5: {
            imageScaleFactor = 0.25;
            break;
        }
        default: {
            std::cerr << "Something went wrong";
            displayScaleFactors();
        }
    }
}

void Menu::displayColorReversion() {
    int input;
    std::cout << "Would you like us to reverse the colors?" << std::endl;
    std::cout << "   " + std::to_string(1) + " - " + "Yes" << std::endl;
    std::cout << "   " + std::to_string(2) + " - " + "No" << std::endl;

    std::cin >> input;
    if (isInputCorrect(input, 2)) {
        chooseColorReversion(input);
    } else {
        displayColorReversion();
    }
}

void Menu::chooseColorReversion(const int &input) {
    switch (input) {
        case 1: {
            isColorReversed = true;
            break;
        }
        case 2: {
            isColorReversed = false;
            break;
        }
        default: std::cerr << "Something went wrong";
    }
}

void Menu::displayImageDisplay() {
    int input;
    std::cout << "Would you like us to display the ASCII image?" << std::endl;
    std::cout << "   " + std::to_string(1) + " - " + "Display and save" << std::endl;
    std::cout << "   " + std::to_string(2) + " - " + "Just save" << std::endl;

    std::cin >> input;
    if (isInputCorrect(input, 2)) {
        chooseIfImageWillBeDisplayed(input);
    } else {
        displayImageDisplay();
    }
}

void Menu::chooseIfImageWillBeDisplayed(const int &input) {
    switch (input) {
        case 1: {
            isImageDisplayed = true;
            break;
        }
        case 2: {
            isImageDisplayed = false;
            break;
        }
        default: std::cerr << "Something went wrong";
    }
    converter->useReverseCharacters(isColorReversed);
}

void Menu::processImage() {
    std::cout << "Processing image..." << std::endl;
    if (isImageDisplayed) {
        std::cout << converter->getASCIIString(imageScaleFactor) << std::endl;
    } else {
        converter->getASCIIString(imageScaleFactor);
    }
    std::cout << "Processing image complete!" << std::endl;
}

void Menu::displayContinue() {
    int input;
    std::cout << "Would you like to generate more images?" << std::endl;
    std::cout << "   " + std::to_string(1) + " - " + "Yes" << std::endl;
    std::cout << "   " + std::to_string(2) + " - " + "No" << std::endl;
    std::cin >> input;

    chooseContinue(input);
}

void Menu::chooseContinue(const int &input) {
    switch (input) {
        case 1: {
            isRunning = true;
            break;
        }
        case 2: {
            isRunning = false;
            break;
        }
        default: std::cerr << "Something went wrong";
    }
}

