#include "Bitmap.h"

#include <fstream>

/* The row size is equal to (3 * width) rounded up to the nearest multiple of 4,
   which we calculate by doing a round-up integer division of (3 * width)/4 and then
   multiplying the result by 4. */
Bitmap::Bitmap(int width, int height) :
    w{width},
    h{height},
    row_size{( (3*w + (4 - 1))/4 ) * 4},
    data{new unsigned char[row_size * h]} {
    std::cout << "Created blank " << w << "x" << h << " bitmap image\n";
}

// Copy constructor
Bitmap::Bitmap(const Bitmap& other) :
    w{other.w},
    h{other.h},
    row_size{other.row_size},
    data{new unsigned char[row_size * h]}
{
    memcpy(data, other.data, row_size * h);
}

// Move constructor
Bitmap::Bitmap(Bitmap&& other) :
    w{other.w},
    h{other.h},
    row_size{other.row_size},
    data{other.data}
{
    other.w = 0;
    other.h = 0;
    other.row_size = 0;
    other.data = nullptr;
}

Bitmap::~Bitmap() {
    delete[] data;
}

// Copy assignment
Bitmap& Bitmap::operator=(const Bitmap& other) {
    if (this != &other) {
        delete[] data;
        w = other.w;
        h = other.h;
        row_size = other.row_size;
        data = new unsigned char[row_size * h];
        memcpy(data, other.data, row_size * h);
    }
    return *this;
}

// Move assignment
Bitmap& Bitmap::operator=(Bitmap&& other) {
    if (this != &other) {
        delete[] data;
        // Assign values to this object
        w = other.w;
        h = other.h;
        row_size = other.row_size;
        data = other.data;

        // Default other object's values
        other.w = 0;
        other.h = 0;
        other.row_size = 0;
        other.data = nullptr;
    }
    return *this;
}

void Bitmap::SetPixel(int x, int y, const Vec3& colour) {
    if (x >= w || x < 0 || y >= h || y < 0) {
        std::cout << "Bitmap pixel (" << x << ", " << y << ") is out of bounds\n";
    } else {
        int offset { y * row_size + x * 3 };
        data[offset + 0] = static_cast<unsigned char>(colour.x * 255.0f);
        data[offset + 1] = static_cast<unsigned char>(colour.y * 255.0f);
        data[offset + 2] = static_cast<unsigned char>(colour.z * 255.0f);
    }
}

bool Bitmap::WriteToDisk(const std::string& filename) const {
    std::ofstream file {filename, std::ios::out | std::ios::binary};
    if (file.is_open()) {
        // TODO: write header
        file.write(reinterpret_cast<char*>(data), row_size * h);
        file.close();
        std::cout << "Finished writing image data to " << filename << "\n";
        return true;
    } else {
        std::cout << "Failed to open file " << filename << " for output\n";
        return false;
    }
}

int Bitmap::Width() const {
    return w;
}

int Bitmap::Height() const {
    return h;
}