#include "include/sierra.h"

void Sierra::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    _width = _image.width();
    _height = _image.height();

    get_color_palette();
    logic();
    save();
}

void Sierra::logic()
{
    for (int r = 0; r < _height; r++)
         for (int c = 0; c < _width; c++)
         {
             set_main_pixel(c,r);
             if(c + 1 < _width)
                set_pixel_value(c + 1, r, 5,32);
             if(c + 2 < _width)
                set_pixel_value(c + 2, r, 3,32);
             if(c - 1 < _width && r + 1 < _height)
                set_pixel_value(c - 1, r + 1, 4, 32);
             if(c - 2 < _width && r + 1 < _height)
                set_pixel_value(c - 2, r + 1, 2, 32);
             if(r + 1 < _height)
                set_pixel_value(c, r + 1, 5, 32);
             if(c + 1 < _width && r + 1 < _height)
                set_pixel_value(c + 1, r + 1, 4, 32);
             if(c + 2 < _width && r + 1 < _height)
                set_pixel_value(c + 2, r + 1, 2, 32);
             if(c - 1 < _width && r + 2 < _height)
                set_pixel_value(c - 1, r + 2, 2, 32);
             if(r + 2 < _height)
                set_pixel_value(c, r + 2, 3, 32);
             if(c + 1 < _width && r + 2 < _height)
                set_pixel_value(c + 1, r + 2, 2, 32);

         }
}

void Sierra::save() const
{
    _image.save_png("");
}

