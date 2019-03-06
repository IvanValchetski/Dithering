#include "include/atkinson.h"

void Atkinson::execute(CImg<unsigned char>& image, const unsigned int palette)
{
    this->_image = image;
    _palette = palette;
    _width = _image.width();
    _height = _image.height();

    get_color_palette();
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
                error_diffusion(c + 1, r,1,8);
            if(c + 2 < _width)
                error_diffusion(c + 2, r,1,8);
            if(c - 1 < _width && r + 1 < _height )
                error_diffusion(c - 1, r + 1, 1, 8);
            if(r + 1 < _height )
                error_diffusion(c, r + 1, 1, 8);
            if(r + 2 < _height)
                error_diffusion(c, r + 2, 1, 8);
            if(c + 1 < _width && r + 1 < _height)
                error_diffusion(c + 1, r + 1, 1, 8);

         }
}

void Atkinson::save() const
{
    _image.save_png("");
}
