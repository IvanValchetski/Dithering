#ifndef ATKINSON_H
#define ATKINSON_H

#include "idither.h"

class Atkinson: public IDither
{
public:
    Atkinson(){}
    ~Atkinson() override{}
    void execute(CImg<unsigned char>& image, const unsigned int palette) override;

private:
    void logic() override;
    void save() override;

};

#endif // ATKINSON_H
