#include "CImg.h"
#include "lib/include/median_cut.h"
#include "lib/include/idither.h"
#include "lib/include/atkinson.h"
#include "lib/include/burkes.h"
#include "lib/include/floyd_steinberg.h"
#include "lib/include/sierra.h"

int main()
{


    CImg<unsigned char> img("");
    std::unique_ptr<IDither> dit(IDither::do_dithering(Atkinson));
    dit->execute(img,64);

    return 0;
}
