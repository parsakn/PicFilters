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
    vector<vector<int>> reds;
    vector<vector<int>> blues;
    vector<vector<int>> greens;


    void initPicture(const string& address);
    void initColors();


public:

Filter(string inputaddres, string outputname,View pictureview);
virtual void applyfilter() = 0;

};


#endif //P6_FILTER_H
