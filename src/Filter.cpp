
#include "Filter.h"


Filter::Filter(const string& inputaddres,const string& output,View pictureview) {
    this->view = pictureview;
    this->outputName = output;
    initPicture(inputaddres);
    initColors();


}

void Filter::initPicture(const string& address) {
    read(inputPicture,address);
}

void Filter::applyfilter() {
    for (int i = view.x; i < this->view.height; ++i) {
        for (int j = view.y; j < this->view.width; ++j) {
            uint8_t avg = this->inputPicture.data[i][j].grn + this->inputPicture.data[i][j].red + this->inputPicture.data[i][j].blu;
            avg = avg / 3;
            this->inputPicture.data[i][j] = Pixel(avg,avg,avg);
        }
    }
    write(this->inputPicture, this->outputName);
    delete this->inputPicture.fileData;
}

void Filter::initColors() {
    vector<uint8_t> test;
    for (int i = 0; i < view.width; ++i) {
        reds.push_back(test);
        blues.push_back(test);
        greens.push_back(test);
        for (int j = 0; j < view.height; ++j) {
            reds[i].push_back(this->inputPicture.data[i][j].red);
            blues[i].push_back(this->inputPicture.data[i][j].blu);
            greens[i].push_back(this->inputPicture.data[i][j].grn);
        }
    }
}
