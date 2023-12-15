#include "GrayScale.h"

GrayScale::GrayScale(string inputaddres, string outputname, View pictureview) : ColorFilter(inputaddres, outputname,
                                                                                       pictureview) {

}

void GrayScale::applyfilter() {
    for (int i = view.x; i < this->view.width; ++i) {
        for (int j = view.y; j < this->view.height; ++j) {
            int avg = this->greens[i][j] + this->reds[i][j] + this->blues[i][j];
            avg = avg / 3;
            this->inputPicture.data[i][j] = Pixel(avg,avg,avg);
        }
    }
    write(this->inputPicture, this->outputName);
    delete this->inputPicture.fileData;
}
