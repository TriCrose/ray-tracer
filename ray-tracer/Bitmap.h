#ifndef BITMAP_H
#define BITMAP_H
#pragma once

#include <string>
#include <array>
#include <vector>

#include "Vector.h"

/* Class representing a bitmap image with 24-bit colour depth */
class Bitmap {
public:
    Bitmap(int width, int height);

    void SetPixel(int x, int y, const Vec3& colour);
    bool WriteToDisk(const std::string& filename) const;
private:
    const int width;
    const int height;

    // This contains both the 14-byte BMP header and the 40-byte DIB header
    static constexpr unsigned kHeaderSize = 14 + 40;
    std::array<unsigned char, kHeaderSize> header;

    // Each row of the pixel data has to be a multiple of 4 bytes, so row_size is not necessarily equal to 3 * width
    const int row_size;
    std::vector<unsigned char> pixel_data;
};

#endif // BITMAP_H