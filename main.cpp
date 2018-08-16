#include "Bitmap.h"

int main(int argc, char** argv) {
    Bitmap image {800, 600};
    image.SetPixel(0, 0, {1.0f});
    image.WriteToDisk("output.bmp");
    system("PAUSE");
    return 0;
}