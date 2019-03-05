#include "idither.h"
#include "floyd_steinberg.h"
#include "burkes.h"
#include "sierra.h"
#include "atkinson.h"

void IDither::setPixelValue(CImg<unsigned char>& image, RGBColors& colors, int c, int r, double mul, double sub)
{
    image(c,r,0,0) += (colors.error_red * mul/sub);
    image(c,r,0,1) += (colors.error_green * mul/sub);
    image(c,r,0,2) += (colors.error_blue * mul/sub);
}

void IDither::setMainPixel(CImg<unsigned char>& image, RGBColors& colors, int c, int r, int _palette)
{
    if(flag)
    {

        int m = 0, s = 0, e=0;
        get_color_palette(image, _palette, image.width(), image.height());
        flag = false;
        /*point:
        for(int k = e; k < 64; k++)
        {
            for(int i = m; i < height; i++){
                for(int j = 0; j < width; j++)
                {
                    image(j,i,0,0) = color_palette.at(k).red;
                    image(j,i,0,1) = color_palette.at(k).green;
                    image(j,i,0,2) = color_palette.at(k).blue;
                    s++;
                }
                m++;
                if(m % 18 == 0){
                    e++;
                    goto point;
                }
            }
}
        image.save_png("/home/ivan/Downloads/Sierra.png");*/

    }

    colors.red = image(c,r,0,0);
    colors.green = image(c,r,0,1);
    colors.blue = image(c,r,0,2);

    //RGBColors temp_color = color_palette.at(find_pixel_color(colors));
    find_pixel_color(colors);

    image(c,r,0,0) = colors.temp_red;
    image(c,r,0,1) = colors.temp_green;
    image(c,r,0,2) = colors.temp_blue;

    colors.error_red = (colors.red - colors.temp_red);
    colors.error_green = (colors.green - colors.temp_green);
    colors.error_blue = (colors.blue - colors.temp_blue);

 }

void IDither::get_color_palette(CImg<unsigned char>& image, int palette, int width, int height)
{
    median_cut mc(image, palette, width, height);
    mc.divide_by_bucket();
    mc.color_calculate();
    color_palette = mc.get_color_palette();
    cout << color_palette.size() << endl;
    for(int i = 0; i < color_palette.size(); i++)
    {
        cout << color_palette[i].red << " " << color_palette[i].green << " " << color_palette[i].blue << endl;
    }
}

void IDither::find_pixel_color(RGBColors& colors)
{
    int best_color, f_min = 10000000;
    double result;
    for(size_t i = 0; i < color_palette.size(); i++)
    {
        result = std::sqrt(std::pow(color_palette[i].red - colors.red,2) +
                std::pow(color_palette[i].green - colors.green,2) +
                std::pow(color_palette[i].blue - colors.blue,2));

        if(result < f_min)
        {
            best_color = i;
            f_min = result;
        }
    }

    colors.temp_red = color_palette[best_color].red;
    colors.temp_green = color_palette[best_color].green;
    colors.temp_blue = color_palette[best_color].blue;

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
