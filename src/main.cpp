#include <iostream>

#include "../include/bmp.hpp"
#include "Filter.h"
#include "ColorFilter.h"
#include "GrayScale.h"
#include "Invert.h"
#include "manual.h"
#include "Emboss.h"
#include "Sharpen.h"
#include "GBlur.h"

int main() {
    Filter* filter1 = new GrayScale(INPUTADDRESS,"outputtest.bmp",View{0,0,356,356});
    filter1->applyfilter();
    cout << "DONE." << endl;
    return 0;


}
