#include "include/idither.h"
#include "include/floyd_steinberg.h"
#include "include/burkes.h"
#include "include/sierra.h"
#include "include/atkinson.h"

void IDither::set_pixel_value(int c, int r, double mul, double sub)
{
    _image(c,r,0,0) += (_colors.error_red * mul/sub);
    _image(c,r,0,1) += (_colors.error_green * mul/sub);
    _image(c,r,0,2) += (_colors.error_blue * mul/sub);
}

void IDither::set_main_pixel(int c, int r)
{
    if(!_flag){
        _flag = true;
        get_color_palette();
    }

    _colors.red = _image(c,r,0,0);
    _colors.green = _image(c,r,0,1);
    _colors.blue = _image(c,r,0,2);

    find_pixel_color(_colors);

    _image(c,r,0,0) = _colors.temp_red;
    _image(c,r,0,1) = _colors.temp_green;
    _image(c,r,0,2) = _colors.temp_blue;

    _colors.error_red = (_colors.temp_red - _colors.red);
    _colors.error_green = (_colors.temp_green - _colors.green);
    _colors.error_blue = (_colors.temp_blue - _colors.blue);

 }

void IDither::get_color_palette()
{
    median_cut mc(_image, _palette, _width, _height);
    mc.divide_by_bucket();
    mc.color_calculate();
    _color_palette = mc.get_color_palette();
}

void IDither::find_pixel_color(RGBColors& colors)
{
    int best_color, f_min = 10000000;
    double result;
    for(size_t i = 0; i < _color_palette.size(); i++)
    {
        result = 30 * std::pow(_color_palette[i].red - colors.red,2) +
                59 * std::pow(_color_palette[i].green - colors.green,2) +
                11 * std::pow(_color_palette[i].blue - colors.blue,2);

        if(result < f_min)
        {
            best_color = i;
            f_min = result;
        }
    }

    colors.temp_red = _color_palette[best_color].red;
    colors.temp_green = _color_palette[best_color].green;
    colors.temp_blue = _color_palette[best_color].blue;

}

IDither* IDither::do_dithering(dit_mode mode)
{

    switch(mode)
    {
    case dit_mode::Floyd:{
        return new Floyd_Steinberg;
        break;
    }
    case dit_mode::Burkes:{
        return new class Burkes;
        break;
    }
    case dit_mode::Sierra:{
        return new class Sierra;
        break;
    }
    case dit_mode::Atkinson:{
        return new class Atkinson;
        break;
    }
    }
}
