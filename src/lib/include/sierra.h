#ifndef SIERRA_H
#define SIERRA_H

#include "idither.h"

class Sierra:  public IDither
{
public:
    Sierra(){}
    ~Sierra() override{}
    void execute(CImg<unsigned char>& image, const unsigned int palette) override;

private:
    void logic() override;
    void save() const override;
};

#endif // SIERRA_H
