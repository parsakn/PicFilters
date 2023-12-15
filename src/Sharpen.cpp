//
// Created by parsa on 12/15/23.
//

#include "Sharpen.h"

Sharpen::Sharpen(string inputaddres, string outputname, View pictureview) : KernelFilter(inputaddres, outputname,
                                                                                   pictureview) {
    this->kernel = {{0,-1,0},{-1,5,-1},{0,-1,0}};
}
