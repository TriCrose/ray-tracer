#include "Scene.h"

namespace {
    inline float radians(float degrees) { return degrees * 3.14159f/180.0f; }
}

int main(int argc, char** argv) {
    Scene scene {1920, 1080, radians(100.0f)};
    scene.SetLight({-1.0f, 10.0f, -5.0f});

    Sphere sphere {{0.0f, 0.0f, -6.0f}, 3.0f};
    scene.AddObject(&sphere);

    scene.Render("output.bmp");
    system("PAUSE");
    return 0;
}