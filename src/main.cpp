#include "CImg.h"
#include "lib/median_cut.h"
#include "lib/idither.h"
#include "lib/atkinson.h"
#include "lib/burkes.h"
#include "lib/floyd_steinberg.h"
#include "lib/sierra.h"


using namespace cimg_library;

int main()
{

    CImg<unsigned char> img("/home/ivan/Downloads/lion.png");

    std::unique_ptr<IDither> dit(IDither::do_dithering(Atkinson));
    dit->execute(img,64);



    return 0;
}
