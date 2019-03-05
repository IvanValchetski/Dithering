#ifndef IMAGEDITHERING_H
#define IMAGEDITHERING_H

#include "CImg.h"
#include <exception>
#include <iostream>
<<<<<<< HEAD
#include "median_cut.h"
#include "pixel.h"
#include "idither.h"

using namespace cimg_library;

/*struct RGBColors{
=======


using namespace cimg_library;

struct RGBColors{
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5
    double red;
    double green;
    double blue;

    char error_red;
    char error_green;
    char error_blue;

    double temp_red;
    double temp_green;
    double temp_blue;
<<<<<<< HEAD
};*/

=======
};
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5

/*struct Point{
    int r{};
    int c{};
};*/

<<<<<<< HEAD
//enum dit_mode: int{Floyd = 1, Burkes, Sierra, Atkinson};
=======
enum dit_mode: int{Floyd = 1, Burkes, Sierra, Atkinson};
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5

class ImageDithering
{
public:
    ImageDithering() = delete ;
<<<<<<< HEAD
    explicit ImageDithering(const char* const path_to_file, const unsigned int palette);
    void Save(const char* const path_to_file);
    void Dithering(const int dit_name);

private:
    const char* const _path_to_file;
    unsigned int _palette;
=======
    explicit ImageDithering(const char* const path_to_file);
    void Save(const char* const path_to_file);
    void Dithering(const int dit_name, int factor = 2);

private:
    const char* const _path_to_file;
    unsigned int palette;
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5

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
<<<<<<< HEAD

    std::vector<pixel> color_palette;
=======
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5
};

#endif // IMAGEDITHERING_H
