#ifndef IDITHER_H
#define IDITHER_H

#include "CImg.h"
#include <exception>
#include <vector>
#include "pixel.h"
#include "median_cut.h"
#include <memory>

using namespace cimg_library;


enum dit_mode: int{Floyd = 1, Burkes, Sierra, Atkinson};

class IDither
{
public:
    IDither(){}
    static IDither* do_dithering(dit_mode mode);
    virtual ~IDither(){}
    virtual void execute(CImg<unsigned char>& image, const unsigned int palette) = 0;

protected:
    CImg<unsigned char> _image;
    size_t _width;
    size_t _height;
    std::vector<RGBColors> _color_palette;
    unsigned int _palette;
    RGBColors _colors;

    void set_pixel_value(int c, int r, double mul, double sub);
    void set_main_pixel(int c, int r);
    void get_color_palette();
    virtual void save() const = 0;
    virtual void logic() = 0;

private:
    void find_pixel_color(RGBColors& color);

};

#endif // IDITHER_H
