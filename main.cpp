#include <iostream>
#include "EasyBMP/EasyBMP.h"
#include "image-to-ascii/BMPToASCII.h"
#include "menu/Menu.h"
#include "image-to-ascii/PNGReader.h"

int main() {

    std::string imagePath = "../pics/thumbs_up.bmp";
    std::string outputPath = "../pics/test.txt";

    Menu menu;
    menu.run();



    PNGReader png(imagePath, outputPath);

    png.loadPicture();
    png.printPicture();

    return 0;
}
