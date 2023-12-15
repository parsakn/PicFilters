
#include "GBlur.h"

GBlur::GBlur(string inputaddres, string outputname, View pictureview) : KernelFilter(inputaddres, outputname, pictureview) {
    this->kernel = {{1,2,1},{2,4,2},{1,2,1}};
}

void GBlur::updateColorsChannel(vector<vector<int>> r, vector<vector<int>> g, vector<vector<int>> b) {
    for (int i = view.x; i < view.width; ++i) {
        for (int j = view.y; j < view.height; ++j) {
            r[i][j] = r[i][j] / 16 ; g[i][j] = g[i][j] / 16 ; b[i][j] = b[i][j] / 16 ;
            r[i][j] = boundCheck(r[i][j]);
            g[i][j] = boundCheck(g[i][j]);
            b[i][j] = boundCheck(b[i][j]);
            reds[i][j] = r[i][j];
            blues[i][j] = b[i][j];
            greens[i][j] = g[i][j];
        }
    }
}
