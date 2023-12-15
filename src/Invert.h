#ifndef P6_INVERT_H
#define P6_INVERT_H

#include "ColorFilter.h"

class Invert : public ColorFilter{

public:
    Invert(string inputaddres, string outputname,View pictureview);
    void applyfilter() override;

};


#endif //P6_INVERT_H
