#ifndef P6_COLORFILTER_H
#define P6_COLORFILTER_H

#include "Filter.h"

class ColorFilter : public Filter{

public:
    virtual void applyfilter() override = 0;
    ColorFilter(string inputaddres, string outputname,View pictureview);

};


#endif //P6_COLORFILTER_H
