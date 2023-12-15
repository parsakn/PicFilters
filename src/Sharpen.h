#ifndef P6_SHARPEN_H
#define P6_SHARPEN_H

#include "KernelFilter.h"
class Sharpen : public KernelFilter{


public:
    Sharpen(string inputaddres, string outputname,View pictureview);
};


#endif //P6_SHARPEN_H
