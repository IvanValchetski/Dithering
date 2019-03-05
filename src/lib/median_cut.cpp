#include "include/median_cut.h"

median_cut::median_cut(CImg<unsigned char>& image, const unsigned int& palette, const size_t width, const size_t height):
    _palette{palette},_width{width},_height{height}
{
    this->_image = image;
    init();
}
void median_cut::init()
{
    for (size_t r = 0; r < _height; r++)
        for(size_t c = 0; c < _width; c++)
        {
            RGBColors temp_pix;
            temp_pix.red = _image(c,r,0,0);
            temp_pix.green = _image(c,r,0,1);
            temp_pix.blue = _image(c,r,0,2);
            _pixels_list.push_back(temp_pix);

        }
}

void median_cut::find_min_max(bucket& buck)
{
    _min.red = _min.green = _min.blue = 255;
    _max.red = _max.green = _max.blue = 0;

    for(size_t c = buck.begin; c < buck.end; c++)
        {
                _min.red = std::min(_min.red, _pixels_list[c].red);
                _max.red = std::max(_max.red, _pixels_list[c].red);
                _min.green = std::min(_min.green, _pixels_list[c].green);
                _max.green = std::max(_max.green, _pixels_list[c].green);
                _min.blue = std::min(_min.blue, _pixels_list[c].blue);
                _max.blue = std::max(_max.blue, _pixels_list[c].blue);
        }


    int max_color{-255};

    double temp_arr[3]{static_cast<double>(_max.red - _min.red), static_cast<double>(_max.green - _min.green), static_cast<double>(_max.blue - _min.blue)};

    for(size_t i = 0; i < 3; i++)
    {
        if(temp_arr[i] > max_color)
        {
            max_color = temp_arr[i];
            max_axis = i;
        }
    }
    buck.num_pix = buck.end - buck.begin;
}

void median_cut::divide_by_bucket()
{
    bucket buck;
    buck.begin = 0;
    buck.end = _pixels_list.size();
    _boxes.push(buck);

    for(size_t i = 0; i < _palette; i++)
    {
        bucket parent, lbox, rbox;
        parent = _boxes.top();
        _boxes.pop();

        find_min_max(parent);

        std::sort(_pixels_list.begin() + parent.begin, _pixels_list.begin() + parent.end, cmp_functions[max_axis]);

        int median = (parent.end - parent.begin)/2;

        lbox.begin = parent.begin;
        lbox.end = parent.begin + median;
        rbox.begin = parent.begin + median + 1;
        rbox.end = parent.end;

        find_min_max(lbox);
        find_min_max(rbox);

        _boxes.push(lbox);
        _boxes.push(rbox);
    }
}


void median_cut::color_calculate()
{
    int num_boxes = _boxes.size();
    for(size_t i = 0; i < num_boxes; i++)
    {
        bucket buck = _boxes.top();
        _boxes.pop();
        _color_palette.push_back(average_color(buck));
    }

}

RGBColors median_cut::average_color(const bucket& buck)
{
    RGBColors pix;
    for(size_t i = buck.begin; i < buck.end; i++)
    {
        RGBColors temp_pix = _pixels_list.at(i);
        pix.red += temp_pix.red;
        pix.green += temp_pix.green;
        pix.blue += temp_pix.blue;
    }
    pix.red = pix.red/buck.num_pix;
    pix.green = pix.green/buck.num_pix;
    pix.blue = pix.blue/buck.num_pix;

    return pix;
}

std::vector<RGBColors> median_cut::get_color_palette() const
{
    return _color_palette;
}

