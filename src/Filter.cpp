
#include "Filter.h"


Filter::Filter( string inputaddres, string output,View pictureview) {
    this->view = pictureview;
    this->outputName = output;
    initPicture(inputaddres);
    initColors();


}

void Filter::initPicture(const string& address) {
    read(inputPicture,address);
}

void Filter::initColors() {
    vector<int> test;
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
