#include "sierra.h"

void Sierra::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    width = _image.width();
    height = _image.height();

    logic();
    save();
}

void Sierra::logic()
{
    for (int r = 0; r < height - 2; r++)
         for (int c = 2; c < width - 2; c++)
         {
             setMainPixel(_image, colors, c,r, _palette);

             setPixelValue(_image, colors, c + 1, r, 5,32);
             setPixelValue(_image, colors, c + 2, r, 3,32);
             setPixelValue(_image, colors, c - 1, r + 1, 4, 32);
             setPixelValue(_image, colors, c - 2, r + 1, 2, 32);
             setPixelValue(_image, colors, c, r + 1, 5, 32);
             setPixelValue(_image, colors, c + 1, r + 1, 4, 32);
             setPixelValue(_image, colors, c + 2, r + 1, 2, 32);
             setPixelValue(_image, colors, c - 1, r + 2, 2, 32);
             setPixelValue(_image, colors, c, r + 2, 3, 32);
             setPixelValue(_image, colors, c + 1, r + 2, 2, 32);

         }
}

void Sierra::save()
{
    _image.save_png("/home/ivan/Downloads/Sierra.png",1);
}

