#include "imagedithering.h"

<<<<<<< HEAD
ImageDithering::ImageDithering(const char* const path_to_file, const unsigned int palette):
    _path_to_file{path_to_file}, _palette{palette}
=======
ImageDithering::ImageDithering(const char* const path_to_file):_path_to_file{path_to_file},palette{1}
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5
{
    image.load(_path_to_file);

    if(image.spectrum() != 3)
        throw std::invalid_argument("your file is a grayscale image");

    width = image.width();
    height = image.height();

<<<<<<< HEAD
    median_cut cp(image,_palette,width,height);
    cp.divide_by_bucket();
    cp.color_calculate();
    color_palette = cp.get_color_palette();
    for(int i = 0; i < color_palette.size(); i++)
    {
        cout << color_palette[i].red << " " << color_palette[i].green << " " << color_palette[i].blue << endl;
    }


=======
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5
}

void ImageDithering::Floyd_Steinberg()
{
   for (int r = 0; r < height - 1; r++)
        for (int c = 1; c < width - 1; c++)
        {
            setMainPixel(c,r);

            setPixelValue(c + 1, r,7,16);
            setPixelValue(c - 1, r + 1, 3, 16);
            setPixelValue(c, r + 1, 5, 16);
            setPixelValue(c + 1, r + 1, 1, 16);
        }
}

void ImageDithering::Burkes()
{
    for (int r = 0; r < height - 1; r++)
        for (int c = 2; c < width - 2; c++)
        {
            setMainPixel(c,r);

            setPixelValue(c + 1, r, 8,32);
            setPixelValue(c + 2, r, 4,32);
            setPixelValue(c - 1, r + 1, 4, 32);
            setPixelValue(c - 2, r + 1, 2, 32);
            setPixelValue(c, r + 1, 8, 32);
            setPixelValue(c + 1, r + 1, 4, 32);
            setPixelValue(c + 2, r + 1, 2, 32);
        }
}

void ImageDithering::Sierra()
{
   for (int r = 0; r < height - 2; r++)
        for (int c = 2; c < width - 2; c++)
        {
            setMainPixel(c,r);

            setPixelValue(c + 1, r, 5,32);
            setPixelValue(c + 2, r, 3,32);
            setPixelValue(c - 1, r + 1, 4, 32);
            setPixelValue(c - 2, r + 1, 2, 32);
            setPixelValue(c, r + 1, 5, 32);
            setPixelValue(c + 1, r + 1, 4, 32);
            setPixelValue(c + 2, r + 1, 2, 32);
            setPixelValue(c - 1, r + 2, 2, 32);
            setPixelValue(c, r + 2, 3, 32);
            setPixelValue(c + 1, r + 2, 2, 32);

        }
}

void ImageDithering::Atkinson()
{
    for (int r = 0; r < height - 2; r++)
         for (int c = 1; c < width - 2; c++)
         {
            setMainPixel(c,r);

            setPixelValue(c + 1, r,1,8);
            setPixelValue(c + 2, r,1,8);
            setPixelValue(c - 1, r + 1, 1, 8);
            setPixelValue(c, r + 1, 1, 8);
            setPixelValue(c, r + 2, 1, 8);
            setPixelValue(c + 1, r + 1, 1, 8);

         }
}

void ImageDithering::setPixelValue(int c, int r, double mul, double sub)
{
<<<<<<< HEAD
    image(c,r,0,0) += (colors.error_red * mul/sub);
    image(c,r,0,1) += (colors.error_green * mul/sub);
    image(c,r,0,2) += (colors.error_blue * mul/sub);
=======
    image(c,r,0,0) += (colors.error_red * (double)mul/(double)sub);
    image(c,r,0,1) += (colors.error_green * (double)mul/(double)sub);
    image(c,r,0,2) += (colors.error_blue * (double)mul/(double)sub);
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5
}

void ImageDithering::Save(const char *const path_to_file)
{
    image.save_png(path_to_file,1);
}

void ImageDithering::doGrayscale()
{
    for(size_t r = 0; r < height; r++)
        for(size_t c = 0; c < width; c++)
        {
            colors.red = image(c,r,0,0);
            colors.green = image(c,r,0,1);
            colors.blue = image(c,r,0,2);
            double grayValue = (0.299 * colors.red + 0.587 * colors.green + 0.114 * colors.blue);
            image(c,r,0,0) = grayValue;
        }
    is_gray_scale = true;
}

void ImageDithering::setMainPixel(int c, int r)
{
    colors.red = image(c,r,0,0);
    colors.green = image(c,r,0,1);
    colors.blue = image(c,r,0,2);

<<<<<<< HEAD
    colors.temp_red = round(_palette * colors.red/255.0) * 255.0/_palette;
    colors.temp_green = round(_palette * colors.green/255.0) * 255.0/_palette;
    colors.temp_blue = round(_palette * colors.green/255.0) * 255.0/_palette;
=======
    colors.temp_red = round(palette * colors.red/255.0) * 255.0/palette;
    colors.temp_green = round(palette * colors.green/255.0) * 255.0/palette;
    colors.temp_blue = round(palette * colors.green/255.0) * 255.0/palette;
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5

    image(c,r,0,0) = colors.temp_red;
    image(c,r,0,1) = colors.temp_green;
    image(c,r,0,2) = colors.temp_blue;

    colors.error_red = (colors.red - colors.temp_red);
    colors.error_green = (colors.green - colors.temp_green);
    colors.error_blue = (colors.blue - colors.temp_blue);

    if(is_gray_scale)
<<<<<<< HEAD
        image(c,r,0,1) = image(c,r,0,2) = image(c,r,0,0);  
}


void ImageDithering::Dithering(const int dit_name)
{
    if(_palette <= 2)
    {
        _palette = 1;
=======
        image(c,r,0,1) = image(c,r,0,2) = image(c,r,0,0);
}


void ImageDithering::Dithering(const int dit_name, int factor)
{
    this->palette = factor;

    if(palette <= 2)
    {
        palette = 1;
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5
        doGrayscale();
    }


    switch(dit_name)
    {
    case dit_mode::Floyd:{
        Floyd_Steinberg();
        break;
    }
    case dit_mode::Burkes:{
        Burkes();
        break;
    }
    case dit_mode::Sierra:{
        Sierra();
        break;
    }
    case dit_mode::Atkinson:{
        Atkinson();
        break;
    }
    default:
        std::cout << "  1 - dithering mode:\n"
                  << "1: Floyd-Steinberg\n"
                  << "2: Burkes\n"
                  << "3: Sierra\n"
                  << "4: Atkinson\n"
                  << "   2 - number of colors\n";
    }
}


