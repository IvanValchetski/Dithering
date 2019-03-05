#include "CImg.h"
<<<<<<< HEAD
#include "lib/median_cut.h"
#include "lib/idither.h"
#include "lib/atkinson.h"
#include "lib/burkes.h"
#include "lib/floyd_steinberg.h"
#include "lib/sierra.h"


using namespace cimg_library;
=======
#include "lib/imagedithering.h"
using namespace std;
using namespace cimg_library;


>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5

int main()
{

<<<<<<< HEAD
    CImg<unsigned char> img("/home/ivan/Downloads/lion.png");

    std::unique_ptr<IDither> dit(IDither::do_dithering(Atkinson));
    dit->execute(img,64);


=======
    ImageDithering image("");
    image.Dithering(4,1);
    image.Save("");
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5

    return 0;
}
