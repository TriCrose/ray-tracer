#ifndef BITMAP_H
#define BITMAP_H
#pragma once

#include <string>
#include "Vector.h"

/* Class representing a bitmap image with 24-bit colour depth */
class Bitmap {
public:
    Bitmap(int width, int height);
    Bitmap(const Bitmap& other);
    Bitmap(Bitmap&& other);
    ~Bitmap();

    Bitmap& operator=(const Bitmap& other);
    Bitmap& operator=(Bitmap&& other);

    void SetPixel(int x, int y, const Vec3& colour);
    bool WriteToDisk(std::string filename);
private:
    int w;
    int h;

    // Each row of the BMP has to be a multiple of 4, so row_size is not necessarily equal to w
    int row_size;

    char* data;
};

#endif // BITMAP_H