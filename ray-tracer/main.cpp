#include "Utils.h"
#include "Scene.h"

int main(int argc, char** argv) {
    Scene scene {800, 600, Utils::ToRadians(100.0f)};
    scene.SetLight({0.0f, 4.0f, 0.0f});

    Sphere sphere {{0.0f, 0.0f, -4.0f}, 3.0f};
    scene.AddObject(&sphere);

    scene.Render("output.bmp");
    return 0;
}