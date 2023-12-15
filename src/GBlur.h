
#ifndef P6_GBLUR_H
#define P6_GBLUR_H

#include "KernelFilter.h"
class GBlur : public KernelFilter{
public:
    GBlur(string inputaddres, string outputname,View pictureview);
    void updateColorsChannel(vector<vector<int>> r , vector<vector<int>> g , vector<vector<int>> b) override;
};


#endif //P6_GBLUR_H
