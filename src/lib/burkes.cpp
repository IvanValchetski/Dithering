#include "include/burkes.h"

void Burkes::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    _width = _image.width();
    _height = _image.height();

    logic();
    save();
}

void Burkes::logic()
{
    for (int r = 0; r < _height; r++)
        for (int c = 0; c < _width; c++)
        {
            set_main_pixel(c, r);
            if(c + 1 < _width)
                set_pixel_value(c + 1, r, 8,32);
            if(c + 2 < _width)
                set_pixel_value(c + 2, r, 4,32);
            if(c - 1 < _width && r + 1 < _height)
                set_pixel_value(c - 1, r + 1, 4, 32);
            if(c - 2 < _width && r + 1 < _height)
                set_pixel_value(c - 2, r + 1, 2, 32);
            if(r + 1 < _height)
                set_pixel_value(c, r + 1, 8, 32);
            if(c + 1 < _width && r + 1 < _height)
                set_pixel_value(c + 1, r + 1, 4, 32);
            if(c + 2 < _width && r + 1 < _height)
                set_pixel_value(c + 2, r + 1, 2, 32);
        }
}

void Burkes::save() const
{
    _image.save_png("");
}
