#include <cmath>

#include "Renderer.h"

int main(int argc, char** argv) {
    Scene::Camera camera {
        1920, 1080,
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, -1.0f},
        100.0f,
        1.0f
    };
    
    Scene::Light light {
        {-1.0f, 10.0f, -5.0f}
    };

    Scene::Sphere sphere {
        {0.0f, 0.0f, -6.0f},
        3.0f
    };

    Renderer r;
    r.Render(camera, light, {&sphere}, "output.bmp");
    return 0;
}