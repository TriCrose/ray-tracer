#ifndef BITMAP_H
#define BITMAP_H
#pragma once

#include <string>
#include "Vector.h"

// TODO: un-const members and add copy/move semantics

/* Class representing a bitmap image with 24-bit colour depth */
class Bitmap {
public:
    Bitmap(int width, int height);
    ~Bitmap();

    void SetPixel(int x, int y, const Vec3& colour);
    bool WriteToDisk(std::string filename);
private:
    const int w;
    const int h;

    // Each row of the BMP has to be a multiple of 4, so row_size is not necessarily equal to w
    const int row_size;

    char* const data;
};

#endif // BITMAP_H