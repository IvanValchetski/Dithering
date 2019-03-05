#include "atkinson.h"

void Atkinson::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    width = _image.width();
    height = _image.height();

    logic();
    save();
}

void Atkinson::logic()
{
    for (int r = 0; r < height - 1; r++)
         for (int c = 0; c < width - 1; c++)
         {
            setMainPixel(_image, colors, c, r, _palette);
            if(c + 1 < width)
                setPixelValue(_image, colors, c + 1, r,1,8);
            if(c + 2 < width)
                setPixelValue(_image, colors, c + 2, r,1,8);
            if(c - 1 < width && r + 1 < height )
                setPixelValue(_image, colors, c - 1, r + 1, 1, 8);
            setPixelValue(_image, colors, c, r + 1, 1, 8);
            if(r + 2 < height)
                setPixelValue(_image, colors, c, r + 2, 1, 8);
            if(c + 1 < width && r + 1 < height)
                setPixelValue(_image, colors, c + 1, r + 1, 1, 8);

         }
}

void Atkinson::save()
{

    _image.save_png("/home/ivan/Downloads/Attkinson.png");
}
