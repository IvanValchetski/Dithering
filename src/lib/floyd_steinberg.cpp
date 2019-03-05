#include "include/floyd_steinberg.h"

void Floyd_Steinberg::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    _width = _image.width();
    _height = _image.height();

    logic();
    save();
}

void Floyd_Steinberg::logic()
{
    for (int r = 0; r < _height; r++)
         for (int c = 0; c < _width; c++)
         {
             set_main_pixel(c, r);
             if(c + 1 < _width)
                set_pixel_value(c + 1, r,7,16);
             if(c - 1 < _width && r + 1 < _height)
                set_pixel_value(c - 1, r + 1, 3, 16);
             if(r + 1 < _height)
                set_pixel_value(c, r + 1, 5, 16);
             if(c + 1 < _width && r + 1 < _height)
                set_pixel_value(c + 1, r + 1, 1, 16);
         }
}

void Floyd_Steinberg::save() const
{
    _image.save_png("");
}

