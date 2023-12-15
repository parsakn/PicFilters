#include "KernelFilter.h"

KernelFilter::KernelFilter(string inputaddres, string outputname, View pictureview) : Filter(inputaddres, outputname,
                                                                                             pictureview) {

}

void KernelFilter::applyfilter() {

    vector<vector<int>> redscopy(reds.size(),vector<int>(reds[0].size(),0));
    vector<vector<int>> bluescopy(blues.size(),vector<int>(blues[0].size(),0));
    vector<vector<int>> greenscopy(greens.size(),vector<int>(greens[0].size(),0));

    for (int x = view.x; x < view.width; ++x) {
        for (int y = view.y; y < view.height; ++y) {

            for (int i = -1 ; i <= 1 ; ++i) {
                for (int j = -1; j <= 1 ; ++j) {
                    int pixelValue = getPixelValue(reds, x + i, y + j);
                    if(pixelValue == -1){pixelValue = getPixelValue(reds, x, y);}
                    redscopy[x][y] += pixelValue * kernel[i + 1][j + 1];

                    pixelValue = getPixelValue(greens, x + i, y + j);
                    if(pixelValue == -1){pixelValue = getPixelValue(greens, x, y);}
                    greenscopy[x][y] += pixelValue * kernel[i + 1][j + 1];

                    pixelValue = getPixelValue(blues, x + i, y + j);
                    if(pixelValue == -1){pixelValue = getPixelValue(blues, x, y);}
                    bluescopy[x][y] += pixelValue * kernel[i + 1][j + 1];
                }
            }
        }
    }
    updateColorsChannel(redscopy,greenscopy,bluescopy);
    this->updatePicture();
    write(this->inputPicture, this->outputName);
    delete this->inputPicture.fileData;
}

int KernelFilter::getPixelValue(vector<vector<int>>& rgb, int x, int y) {
    if (x >= 0 && x < rgb.size() && y >= 0 && y < rgb[0].size()) {
        return rgb[x][y];
    } else {
        return -1;
    }
}

void KernelFilter::updatePicture() {
    for (int i = view.x; i < view.width; ++i) {
        for (int j = view.y; j < view.height; ++j) {
            uint8_t red = reds[i][j];
            uint8_t blue = blues[i][j];
            uint8_t green = greens[i][j];
            this->inputPicture.data[i][j] = Pixel(red,green,blue);
        }
    }
}

void KernelFilter::updateColorsChannel(vector<vector<int>> r, vector<vector<int>> g, vector<vector<int>> b) {
    for (int i = view.x; i < view.width; ++i) {
        for (int j = view.y; j < view.height; ++j) {
            r[i][j] = boundCheck(r[i][j]);
            g[i][j] = boundCheck(g[i][j]);
            b[i][j] = boundCheck(b[i][j]);
            reds[i][j] = r[i][j];
            blues[i][j] = b[i][j];
            greens[i][j] = g[i][j];
        }
    }
}

int KernelFilter::boundCheck(int number) {
    if (number > 255){
        return 255;
    } else if (number < 0){
        return 0;
    } else{
        return number;
    }

}
