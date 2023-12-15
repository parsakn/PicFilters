#ifndef P6_FILTER_H
#define P6_FILTER_H

#include "../include/bmp.hpp"
#include "iostream"
#include "manual.h"
#include "vector"
#include "../include/bmp.hpp"
#include <cstdint>

using namespace std;

class Filter {
protected:
    Bmp inputPicture;
    View view;
    string outputName;
    vector<vector<uint8_t>> reds;
    vector<vector<uint8_t>> blues;
    vector<vector<uint8_t>> greens;


    void initPicture(const string& address);
    void initColors();


public:

Filter(const string& inputaddres,const string& outputname,View pictureview);
virtual void applyfilter();

};


#endif //P6_FILTER_H
