#ifndef PIXEL_H
#define PIXEL_H

/*class pixel
{
public:
    int red{};
    int green{};
    int blue{};
};*/

struct RGBColors{
    int red;
    int green;
    int blue;

    char error_red;
    char error_green;
    char error_blue;

    int temp_red;
    int temp_green;
    int temp_blue;
};

#endif // PIXEL_H
