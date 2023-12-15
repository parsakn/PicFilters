#ifndef P6_GRAYSCALE_H
#define P6_GRAYSCALE_H

#include "ColorFilter.h"

class GrayScale : public ColorFilter{
public:
    GrayScale(string inputaddres, string outputname,View pictureview);
    void applyfilter() override;
};


#endif //P6_GRAYSCALE_H
