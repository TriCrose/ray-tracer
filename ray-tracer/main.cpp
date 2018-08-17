#include "Vector.h"

int main(int argc, char** argv) {
    Vec3 a {10.5f};
    Vec3 b {1.0f, -5.0f, 0.68f};
    std::cout << 1.0f / (a + b) << "\n";
    system("PAUSE");
    return 0;
}