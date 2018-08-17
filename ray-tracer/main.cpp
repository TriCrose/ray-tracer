#include "Bitmap.h"

int main(int argc, char** argv) {
    Bitmap image {1920, 1080};
    for (int i = 0; i < image.Width(); i++) for (int j = 0; j < image.Height(); j++) {
        float i_factor = static_cast<float>(i) / static_cast<float>(image.Width());
        float j_factor = static_cast<float>(j) / static_cast<float>(image.Height());
        image.SetPixel(i, j, {
            i_factor * 0.1f + j_factor * 0.9f,
            i_factor * 0.6f + j_factor * 0.4f,
            i_factor * 0.75f + j_factor * 0.25f
        });
    }
    image.WriteToDisk("output.bmp");
    return 0;
}