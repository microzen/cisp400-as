#include "ImageEditor.h"
#include <math.h>

ImageEditor::ImageEditor(string inFileName) {
    Picture pic(inFileName);
    this->pic = pic;
}

void ImageEditor::swapPixels(int x1, int y1, int x2, int y2) {
    int tr, tg, tb;
    int tr2, tg2, tb2;

    tr = this->pic.red(x1, y1);
    tg = this->pic.green(x1, y1);
    tb = this->pic.blue(x1, y1);

    tr2 = this->pic.red(x2, y2);
    tg2 = this->pic.green(x2, y2);
    tb2 = this->pic.blue(x2, y2);

    this->pic.set(x1, y1, tr2, tg2, tb2);
    this->pic.set(x2, y2, tr, tg, tb);
}

void ImageEditor::flipHorizontal() {
    int mid = this->pic.height() / 2;
//    if (mid % 2 != 0)mid--;
    for (int x = 0; x < pic.width(); ++x) {
        for (int y = 0; y < mid; ++y) {
            int y2 = this->pic.height() - y - 1;
            swapPixels(x, y, x, y2);
        }
    }
}

void ImageEditor::flipVertical() {
    int mid = this->pic.width() / 2;
//    if (mid % 2 == 0)mid--;
    for (int x = 0; x < mid; ++x) {
        for (int y = 0; y < pic.height(); ++y) {
            int x2 = pic.width() - x - 1;
            swapPixels(x, y, x2, y);
        }
    }
}

void ImageEditor::colorFilter(int redTarget, int greenTarget, int blueTarget, int tolerance, int newRed, int newGreen,
                              int newBlue) {
    for (int x = 0; x < this->pic.width(); ++x) {
        for (int y = 0; y < this->pic.height(); ++y) {
            bool r = fabs(pic.red(x, y) - redTarget) <= tolerance;
            bool g = fabs(pic.green(x, y) - greenTarget) <= tolerance;
            bool b = fabs(pic.blue(x, y) - blueTarget) <= tolerance;
            if (r && g && b) {
                this->pic.set(x, y, newRed, newGreen, newBlue);
            }
        }
    }
}

void ImageEditor::doubleSize() {
    Picture newpic(this->pic.width() * 2, this->pic.height() * 2);
    for (int x = 0; x < this->pic.width(); ++x) {
        for (int y = 0; y < this->pic.height(); ++y) {
            int r = this->pic.red(x, y);
            int g = this->pic.green(x, y);
            int b = this->pic.blue(x, y);
            newpic.set(x * 2, y * 2, r, g, b);
            newpic.set(x * 2 + 1, y * 2, r, g, b);
            newpic.set(x * 2, y * 2 + 1, r, g, b);
            newpic.set(x * 2 + 1, y * 2 + 1, r, g, b);
        }
    }
    this->pic = newpic;
}

void ImageEditor::save(string outFileName) {
    this->pic.save(outFileName);
}