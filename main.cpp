#include <iostream>
#include "EasyBMP/EasyBMP.h"
#include "image-to-ascii/BMPToASCII.h"

int main() {

    std::string imagePath = "../pics/test2.bmp";
    std::string outputPath = "../pics/test5.txt";

    auto *bmpToASCII = new BMPToASCII(imagePath, outputPath);
    std::cout << bmpToASCII->getASCIIString(0.35, true) << std::endl;

    delete bmpToASCII;


    /*cout << endl
         << "Using EasyBMP Version " << _EasyBMP_Version_ << endl << endl
         << "Copyright (c) by the EasyBMP Project 2005-6" << endl
         << "WWW: http://easybmp.sourceforge.net" << endl << endl;

    BMP Text;
    Text.ReadFromFile("../sample/EasyBMPtext.bmp");

    BMP Background;
    Background.ReadFromFile("../sample/EasyBMPbackground.bmp");

    BMP Output;
    Output.SetSize( Background.TellWidth() , Background.TellHeight() );
    Output.SetBitDepth( 24 );

    RangedPixelToPixelCopy( Background, 0, Output.TellWidth()-1,
                            Output.TellHeight()-1 , 0,
                            Output, 0,0 );

    RangedPixelToPixelCopyTransparent( Text, 0, 380,
                                       43, 0,
                                       Output, 110,5,
                                       *Text(0,0) );

    RangedPixelToPixelCopyTransparent( Text, 0, Text.TellWidth()-1,
                                       Text.TellWidth()-1, 50,
                                       Output, 100,442,
                                       *Text(0,49) );

    Output.SetBitDepth( 32 );
    cout << "writing 32bpp ... " << endl;
    Output.WriteToFile( "EasyBMPoutput32bpp.bmp" );

    Output.SetBitDepth( 24 );
    cout << "writing 24bpp ... " << endl;
    Output.WriteToFile( "EasyBMPoutput24bpp.bmp" );

    Output.SetBitDepth( 8 );
    cout << "writing 8bpp ... " << endl;
    Output.WriteToFile( "EasyBMPoutput8bpp.bmp" );

    Output.SetBitDepth( 4 );
    cout << "writing 4bpp ... " << endl;
    Output.WriteToFile( "EasyBMPoutput4bpp.bmp" );

    Output.SetBitDepth( 1 );
    cout << "writing 1bpp ... " << endl;
    Output.WriteToFile( "EasyBMPoutput1bpp.bmp" );

    Output.SetBitDepth( 24 );
    Rescale( Output, 'p' , 50 );
    cout << "writing 24bpp scaled image ..." << endl;
    Output.WriteToFile( "EasyBMPoutput24bpp_rescaled.bmp" );*/
    return 0;
}
