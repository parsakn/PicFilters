#include <iostream>

#include "../include/bmp.hpp"
#include "Filter.h"
#include "manual.h"

int main() {

    Filter myfilter(INPUTADDRESS,"outputtest.bmp",View{0,0,100,100});
    myfilter.applyfilter();
    cout << "DONE." << endl;
    /*
    Bmp bmp;
    read(bmp,"/home/parsa/CLionProjects/P6/A6-Sample-Picture.bmp");
    bmp.data[0][0] = Pixel(0,255,0);
    write(bmp, "test12345.bmp");
    delete bmp.fileData;
    */
    return 0;


}
