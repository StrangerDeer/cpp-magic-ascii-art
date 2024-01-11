#include <iostream>
#include "EasyBMP/EasyBMP.h"
#include "image-to-ascii/BMPToASCII.h"
#include "image-to-ascii/PNGReader.h"

int main() {

    std::string imagePath = "../pics/test2.png";
    std::string outputPath = "../pics/test6.txt";

    PNGReader png(imagePath, outputPath);

    png.loadPicture();
    png.printPicture();

    return 0;
}
