#include "Utils.h"
#include "Scene.h"

int main(int argc, char** argv) {
    Scene scene {1024, 768, Utils::ToRadians(100.0f)};
    scene.SetLight({-2.0f, 4.0f, 1.5f}, {0.83f, 0.37f, 0.21f});

    Sphere sphere {{0.0f, 0.0f, -4.0f}, 3.0f};
    scene.AddObject(&sphere);

    scene.Render("output.bmp");
    return 0;
}