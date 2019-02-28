#ifndef IMAGEDITHERING_H
#define IMAGEDITHERING_H

#include "CImg.h"
#include <exception>
#include <iostream>


using namespace cimg_library;

struct RGBColors{
    double red;
    double green;
    double blue;

    char error_red;
    char error_green;
    char error_blue;

    double temp_red;
    double temp_green;
    double temp_blue;
};

/*struct Point{
    int r{};
    int c{};
};*/

enum dit_mode: int{Floyd = 1, Burkes, Sierra, Atkinson};

class ImageDithering
{
public:
    ImageDithering() = delete ;
    explicit ImageDithering(const char* const path_to_file);
    void Save(const char* const path_to_file);
    void Dithering(const int dit_name, int factor = 2);

private:
    const char* const _path_to_file;
    unsigned int palette;

    CImg<unsigned char> image;

    RGBColors colors;

    void setPixelValue(int c, int r, double mul, double sub);
    void doGrayscale();
    void setMainPixel(int c, int r);
    void Floyd_Steinberg();
    void Burkes();
    void Sierra();
    void Atkinson();


    size_t width;
    size_t height;
    bool is_gray_scale{};
};

#endif // IMAGEDITHERING_H
