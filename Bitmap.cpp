#include "Bitmap.h"

/* The row size is equal to (3 * width) rounded up to the nearest multiple of 4,
   which we calculate by doing a round-up integer division of (3 * width)/4 and then
   multiplying the result by 4. */
Bitmap::Bitmap(int width, int height) :
    w{width},
    h{height},
    row_size{( (3*w + 4 - 1)/4 ) * 4},
    data{new char[row_size * h]} {
}

void Bitmap::SetPixel(int x, int y, const Vec3& colour) {
    int offset = y * row_size + x * 3;
    data[offset + 0] = static_cast<char>(colour.x * 255.0f);
    data[offset + 1] = static_cast<char>(colour.y * 255.0f);
    data[offset + 2] = static_cast<char>(colour.z * 255.0f);
}

bool Bitmap::WriteToDisk(std::string filename) {

}

Bitmap::~Bitmap() {
    delete[] data;
}