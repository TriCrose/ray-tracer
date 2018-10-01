#include "Utils.h"
#include "Scene.h"

int main(int argc, char** argv) {
    auto scene = Scene{1280, 1024, Utils::ToRadians(100.0f)};
    scene.SetLight({-2.0f, 4.0f, 1.5f}, {0.53f, 0.37f, 0.91f});

    scene.AddObject(std::make_unique<Sphere>(Vec3{0.0f, 0.0f, -4.0f}, 3.0f));

    scene.Render("output.bmp");
    return 0;
}