#ifndef IDITHER_H
#define IDITHER_H

#include "CImg.h"
#include <exception>
#include <vector>
#include "pixel.h"
#include "median_cut.h"
#include <mutex>
#include <memory>

using namespace cimg_library;


enum dit_mode: int{Floyd = 1, Burkes, Sierra, Atkinson};

class IDither
{
public:
    IDither(){}
    static IDither* do_dithering(dit_mode mode);
    virtual void execute(CImg<unsigned char>& image, const unsigned int palette) = 0;
    virtual ~IDither(){}
    void setPixelValue(CImg<unsigned char>& image, RGBColors& colors, int c, int r, double mul, double sub);
    void setMainPixel(CImg<unsigned char>& image, RGBColors& colors, int c, int r, int _palette);
    void get_color_palette(CImg<unsigned char>& image, int palette, int width, int height);
    virtual void save() = 0;
    virtual void logic() = 0;

protected:
    CImg<unsigned char> _image;
    size_t width;
    size_t height;
    std::vector<RGBColors> color_palette;
    unsigned int _palette;
    RGBColors colors;
    bool flag = true;

private:
    void find_pixel_color(RGBColors& color);

};

#endif // IDITHER_H
