#ifndef FLOYD_STEINBERG_H
#define FLOYD_STEINBERG_H


#include "idither.h"

class Floyd_Steinberg: public IDither
{
public:
    Floyd_Steinberg(){}
    ~Floyd_Steinberg() override{}
    void execute(CImg<unsigned char>& image, const unsigned int palette) override;

private:
    void logic() override;
    void save() override;

};

#endif // FLOYD_STEINBERG_H
