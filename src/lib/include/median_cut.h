#ifndef MEDIAN_CUT_H
#define MEDIAN_CUT_H

#include "CImg.h"
#include <vector>
#include <functional>
#include <queue>
#include "pixel.h"

using namespace cimg_library;

struct bucket
{
    int begin, end;
    int num_pix;
    bool operator<(const bucket& buck) const{
            return (num_pix < buck.num_pix);
        }
};

class median_cut
{
public:
    explicit median_cut(CImg<unsigned char>& image, const unsigned int& palette, const size_t width, const size_t height);
    void divide_by_bucket();
    void color_calculate();
    std::vector<RGBColors> get_color_palette() const;
private:
    CImg<unsigned char> _image;
    const size_t _width;
    const size_t _height;
    unsigned int _palette;

    std::vector<std::function<bool(RGBColors&,RGBColors&)>> cmp_functions{
                                      [](RGBColors& red1, RGBColors& red2){return red1.red < red2.red;},
                                      [](RGBColors& green1, RGBColors& green2){return green1.green < green2.green;},
                                      [](RGBColors& blue1, RGBColors& blue2){return blue1.blue < blue2.blue;}};

    std::vector<RGBColors> _pixels_list;
    std::priority_queue<bucket> _boxes;
    std::vector<RGBColors> _color_palette;

    RGBColors _pix;
    RGBColors _min;
    RGBColors _max;
    int max_axis;

    void init();
    void find_min_max(bucket& buck);
    RGBColors average_color(const bucket& buck);

};

#endif // MEDIAN_CUT_H
