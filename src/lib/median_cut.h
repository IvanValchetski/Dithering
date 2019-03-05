#ifndef MEDIAN_CUT_H
#define MEDIAN_CUT_H

#include <iostream>
#include "CImg.h"
#include <vector>
#include <functional>
#include <queue>
#include "pixel.h"

using namespace cimg_library;
using std::cout;
using std::endl;

struct bucket
{
    int begin, end;
    int num_pix;// max_axis;
    bool operator<(const bucket& buck) const{
            return (num_pix < buck.num_pix);
        }
};

static bool cmpB(const RGBColors& i, const RGBColors& j) {return (i.red < j.red);}
static bool cmpG(const RGBColors& i, const RGBColors& j) {return (i.green < j.green);}
static bool cmpR(const RGBColors& i, const RGBColors& j) {return (i.blue < j.blue);}

class median_cut
{
public:
    explicit median_cut(CImg<unsigned char>& image, const unsigned int& palette, const size_t width, const size_t height);
    void divide_by_bucket();
    void color_calculate();
    std::vector<RGBColors> get_color_palette();
private:
    CImg<unsigned char> image;
    const size_t width;
    const size_t height;
    unsigned int palette;

    std::vector<std::function<bool(RGBColors&,RGBColors&)>> cmp_functions{
                                      [](RGBColors& red1, RGBColors& red2){return red1.red < red2.red;},
                                      [](RGBColors& green1, RGBColors& green2){return green1.green < green2.green;},
                                      [](RGBColors& blue1, RGBColors& blue2){return blue1.blue < blue2.blue;}};

    bool (*cmp[3])(const RGBColors&, const RGBColors&) = {cmpB, cmpG, cmpR};

    std::vector<RGBColors> pixels_list;
    std::priority_queue<bucket> boxes;
    std::vector<RGBColors> color_palette;

    RGBColors pix;
    RGBColors min;
    RGBColors max;
    int max_axis;

    void init();
    void find_min_max(bucket& buck);
    RGBColors average_color(const bucket& buck);

};

#endif // MEDIAN_CUT_H
