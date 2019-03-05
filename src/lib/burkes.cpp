#include "burkes.h"

void Burkes::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    width = _image.width();
    height = _image.height();

    logic();
    save();
}

void Burkes::logic()
{
    for (int r = 0; r < height - 1; r++)
        for (int c = 2; c < width - 2; c++)
        {
            setMainPixel(_image, colors, c,r, _palette);

            setPixelValue(_image, colors, c + 1, r, 8,32);
            setPixelValue(_image, colors, c + 2, r, 4,32);
            setPixelValue(_image, colors, c - 1, r + 1, 4, 32);
            setPixelValue(_image, colors, c - 2, r + 1, 2, 32);
            setPixelValue(_image, colors, c, r + 1, 8, 32);
            setPixelValue(_image, colors, c + 1, r + 1, 4, 32);
            setPixelValue(_image, colors, c + 2, r + 1, 2, 32);
        }
}

void Burkes::save()
{
    _image.save_png("/home/ivan/Downloads/Burkes.png",1);
}
