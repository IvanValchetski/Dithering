#include "floyd_steinberg.h"

void Floyd_Steinberg::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    width = _image.width();
    height = _image.height();

    logic();
    save();
}

void Floyd_Steinberg::logic()
{
    for (int r = 0; r < height - 1; r++)
         for (int c = 1; c < width - 1; c++)
         {
             setMainPixel(_image, colors, c, r, _palette);

             setPixelValue(_image, colors, c + 1, r,7,16);
             setPixelValue(_image, colors, c - 1, r + 1, 3, 16);
             setPixelValue(_image, colors, c, r + 1, 5, 16);
             setPixelValue(_image, colors, c + 1, r + 1, 1, 16);
         }
}

void Floyd_Steinberg::save()
{
    _image.save_png("/home/ivan/Downloads/Floyd.png",1);
}

