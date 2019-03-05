#include "median_cut.h"

median_cut::median_cut(CImg<unsigned char>& image, const unsigned int& palette, const size_t width, const size_t height):
    palette{palette},width{width},height{height}
{
    this->image = image;
    cout << palette << " " << width << " " << height  <<"\n";
    init();
}
void median_cut::init()
{
    for (size_t r = 0; r < height; r++)
        for(size_t c = 0; c < width; c++)
        {
            RGBColors temp_pix;
            temp_pix.red = image(c,r,0,0);
            temp_pix.green = image(c,r,0,1);
            temp_pix.blue = image(c,r,0,2);

            if( (temp_pix.red!=0) && (temp_pix.green!=0) && (temp_pix.blue!=0) )
                           pixels_list.push_back(temp_pix);



        }
}

void median_cut::find_min_max(bucket& buck)
{
    min.red = 255;
    max.red = 0;

    min.green = 255;
    max.green = 0;

    min.blue = 255;
    max.blue = 0;
    for(size_t c = buck.begin; c < buck.end; c++)
        {
                min.red = std::min(min.red, pixels_list[c].red);
                max.red = std::max(max.red, pixels_list[c].red);
                min.green = std::min(min.green, pixels_list[c].green);
                max.green = std::max(max.green, pixels_list[c].green);
                min.blue = std::min(min.blue, pixels_list[c].blue);
                max.blue = std::max(max.blue, pixels_list[c].blue);
        }


    int max_color{-255};

    double temp_arr[3]{static_cast<double>(max.red - min.red), static_cast<double>(max.green - min.green), static_cast<double>(max.blue - min.blue)};

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
    buck.end = pixels_list.size();
    boxes.push(buck);

    for(size_t i = 0; i < palette - 1; i++)
    {
        bucket parent, lbox, rbox;
        parent = boxes.top();
        boxes.pop();

        find_min_max(parent);

        std::sort(pixels_list.begin() + parent.begin, pixels_list.begin() + parent.end, cmp_functions[max_axis]);

        int median = (parent.end - parent.begin + 1)/2;

        if(parent.num_pix < 10 )
            continue;

        lbox.begin = parent.begin;
        lbox.end = parent.begin + median;
        rbox.begin = parent.begin + median;
        rbox.end = parent.end;

        find_min_max(lbox);
        find_min_max(rbox);

        boxes.push(lbox);
        boxes.push(rbox);
    }
}


void median_cut::color_calculate()
{
    int num_boxes = boxes.size();
    for(size_t i = 0; i < num_boxes; i++)
    {
        bucket buck = boxes.top();
        boxes.pop();
        color_palette.push_back(average_color(buck));
    }

}

RGBColors median_cut::average_color(const bucket& buck)
{
    RGBColors pix;
    for(size_t i = buck.begin; i < buck.end; i++)
    {
        RGBColors temp_pix = pixels_list.at(i);
        pix.red += temp_pix.red;
        pix.green += temp_pix.green;
        pix.blue += temp_pix.blue;
    }
    pix.red = pix.red/buck.num_pix;
    pix.green = pix.green/buck.num_pix;
    pix.blue = pix.blue/buck.num_pix;

    return pix;
}

std::vector<RGBColors> median_cut::get_color_palette()
{
    return color_palette;
}

