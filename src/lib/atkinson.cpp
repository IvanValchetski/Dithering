#include "include/atkinson.h"

void Atkinson::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    _width = _image.width();
    _height = _image.height();

    logic();
    save();
}

void Atkinson::logic()
{
    for (int r = 0; r < _height; r++)
         for (int c = 0; c < _width; c++)
         {
            set_main_pixel(c, r);
            if(c + 1 < _width)
                set_pixel_value(c + 1, r,1,8);
            if(c + 2 < _width)
                set_pixel_value(c + 2, r,1,8);
            if(c - 1 < _width && r + 1 < _height )
                set_pixel_value(c - 1, r + 1, 1, 8);
            if(r + 1 < _height )
                set_pixel_value(c, r + 1, 1, 8);
            if(r + 2 < _height)
                set_pixel_value(c, r + 2, 1, 8);
            if(c + 1 < _width && r + 1 < _height)
                set_pixel_value(c + 1, r + 1, 1, 8);

         }
}

void Atkinson::save() const
{
    _image.save_png("/home/ivan/C++/Matrix_cut/own_median/Median_cut/Task/examples/AtkinsonLena.png");
}
