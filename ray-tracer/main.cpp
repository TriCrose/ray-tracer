#include "Utils.h"
#include "Scene.h"

int main(int argc, char** argv) {
    Scene scene {1920, 1080, Utils::ToRadians(100.0f)};
    scene.SetLight({-1.0f, 10.0f, -5.0f});

    Sphere sphere {{0.0f, 0.0f, -6.0f}, 3.0f};
    scene.AddObject(&sphere);

    scene.Render("output.bmp");
    return 0;
}