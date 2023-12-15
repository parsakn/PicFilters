
#ifndef P6_KERNELFILTER_H
#define P6_KERNELFILTER_H

#include "Filter.h"
#include "cstdint"
#include "vector"

class KernelFilter : public Filter{

protected:
    vector<vector<int>> kernel;
    int getPixelValue(vector<vector<int>>& rgb,int x,int y);
    void updatePicture();
    int boundCheck(int number);

public:
    KernelFilter(string inputaddres, string outputname,View pictureview);
    virtual void applyfilter() override;
    virtual void updateColorsChannel(vector<vector<int>> r , vector<vector<int>> g , vector<vector<int>> b);


};


#endif //P6_KERNELFILTER_H
