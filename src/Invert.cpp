//
// Created by parsa on 12/15/23.
//

#include "Invert.h"

Invert::Invert(string inputaddres, string outputname, View pictureview) : ColorFilter(inputaddres, outputname, pictureview) {

}

void Invert::applyfilter() {
    for (int i = view.x; i < this->view.width; ++i) {
        for (int j = view.y; j < this->view.height; ++j) {
            uint8_t red_n = 255 - reds[i][j];
            uint8_t green_n = 255 - greens[i][j];
            uint8_t blue_n = 255 - blues[i][j];

            this->inputPicture.data[i][j] = Pixel(red_n,green_n,blue_n);
        }
    }
    write(this->inputPicture, this->outputName);
    delete this->inputPicture.fileData;
}

