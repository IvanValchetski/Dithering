#ifndef BURKES_H
#define BURKES_H

#include "idither.h"

class Burkes: public IDither
{
public:
    Burkes(){}
    ~Burkes() override{}
    void execute(CImg<unsigned char>& image, const unsigned int palette) override;

private:
    void logic() override;
    void save() override;
};

#endif // BURKES_H
