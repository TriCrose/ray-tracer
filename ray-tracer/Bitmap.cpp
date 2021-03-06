#include <fstream>

#include "Bitmap.h"

/* The row size is equal to (3 * width) rounded up to the nearest multiple of 4,
   which we calculate by doing a round-up integer division of (3 * width)/4 and then
   multiplying the result by 4. Also note that for the initialization of pixel_data
   we use parentheses instead of braces. This is so that the compiler chooses the fill
   constructor rather than attmempting to use the initializer_list constructor. */
Bitmap::Bitmap(int width, int height) :
    width       {width},
    height      {height},
    row_size    {( (3*width + (4 - 1))/4 ) * 4},
    pixel_data  ((row_size * height), 0)        // Note parentheses, see above
{

    auto data_size = pixel_data.size();
    auto file_size = kHeaderSize + data_size;

    // Create the header (note: integers are little-endian, hence the shifting)
    header = {
        // Required BMP file starting signature (2 bytes)
        'B', 'M',

        // Total file size (4 bytes)
        static_cast<unsigned char>(file_size >> 0),
        static_cast<unsigned char>(file_size >> 8),
        static_cast<unsigned char>(file_size >> 16),
        static_cast<unsigned char>(file_size >> 24),

        // Reserved (2 x 2 bytes)
        0, 0, 0, 0,

        // Offset of the pixel data (4 bytes)
        static_cast<unsigned char>(kHeaderSize >> 0),
        static_cast<unsigned char>(kHeaderSize >> 8),
        static_cast<unsigned char>(kHeaderSize >> 16),
        static_cast<unsigned char>(kHeaderSize >> 24),

        // DIB header size, which is 40 (4 bytes)
        40, 0, 0, 0,

        // Width of the image (4 bytes)
        static_cast<unsigned char>(width >> 0),
        static_cast<unsigned char>(width >> 8),
        static_cast<unsigned char>(width >> 16),
        static_cast<unsigned char>(width >> 24),

        // Height of the image (4 bytes)
        static_cast<unsigned char>(height >> 0),
        static_cast<unsigned char>(height >> 8),
        static_cast<unsigned char>(height >> 16),
        static_cast<unsigned char>(height >> 24),

        1, 0,              // Number of colour planes, which is 1 (2 bytes)
        24, 0,             // Bit depth, which is 24 (2 bytes)
        0, 0, 0, 0,        // Compression method, which is none (4 bytes)

        // Size of the raw pixel data (4 bytes)
        static_cast<unsigned char>(data_size >> 0),
        static_cast<unsigned char>(data_size >> 8),
        static_cast<unsigned char>(data_size >> 16),
        static_cast<unsigned char>(data_size >> 24),

        19, 11, 0, 0,      // Horizontal resolution, which is 72 DPI (4 bytes)
        19, 11, 0, 0,      // Vertical resolution, which is 72 DPI (4 bytes)
        0, 0, 0, 0,        // Number of colours in the palette (4 bytes)
        0, 0, 0, 0         // Number of important colours (4 bytes)
    };
}

void Bitmap::SetPixel(int x, int y, const Vec3& colour) {
    if (0 <= x && x < width && 0 <= y && y < height) {
        auto offset = y * row_size + x * 3;
        // Bitmap colour data is stored as BGR instead of RGB
        pixel_data[offset + 0] = static_cast<unsigned char>(colour.z * 255.0f);
        pixel_data[offset + 1] = static_cast<unsigned char>(colour.y * 255.0f);
        pixel_data[offset + 2] = static_cast<unsigned char>(colour.x * 255.0f);
    } else {
        std::cout << "Bitmap pixel (" << x << ", " << y << ") is out of bounds\n";
    }
}

bool Bitmap::WriteToDisk(const std::string& filename) const {
    auto file = std::ofstream{filename, std::ios::out | std::ios::binary};
    if (file.is_open()) {
        // Use the default C locale so the output isn't locale-dependent
        file.imbue(std::locale::classic());

        // These reintepret_cast<>s are safe because the char data is read purely as a sequence of bytes
        file.write(reinterpret_cast<const char*>(header.data()), header.size());
        file.write(reinterpret_cast<const char*>(pixel_data.data()), pixel_data.size());

        file.close();
        return true;
    } else {
        return false;
    }
}