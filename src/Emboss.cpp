//
// Created by parsa on 12/15/23.
//

#include "Emboss.h"

Emboss::Emboss(string inputaddres, string outputname, View pictureview) : KernelFilter(inputaddres, outputname, pictureview) {
    this->kernel = {{-2,-1,0},{-1,1,1},{0,1,2}};
}


