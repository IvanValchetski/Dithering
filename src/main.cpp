#include "CImg.h"
#include "lib/imagedithering.h"
using namespace std;
using namespace cimg_library;



int main()
{

    ImageDithering image("");
    image.Dithering(4,1);
    image.Save("");

    return 0;
}
