#include "Bitmap.h"

int main(int argc, char** argv) {
    auto a = Vec3{};
    a += Vec3{0.0f, 1.0f, -5.5f};
    auto b = a * 4;
    b /= 2;
    b = -b;
    std::cout << a << "\n" << b << "\n";
    system("PAUSE");
    return 0;
}