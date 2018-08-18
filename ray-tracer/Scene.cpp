#include "Scene.h"

using namespace Scene;

// Light
Light::Light(Vec3 position) : position{position}, colour{1.0f} {}
Light::Light(Vec3 position, Vec3 colour) : position{position}, colour{colour} {}

// Camera
Camera::Camera(int image_width, int image_height, float near_plane) :
    image_width{image_width},
    image_height{image_height},
    // TODO: work out some good default values
    near_plane{near_plane} {}

Camera::Camera(int image_width, int image_height, Vec3 position, Vec3 dir, float fov, float near_plane) :
    image_width{image_width},
    image_height{image_height},
    position{position},
    dir{dir},
    fov{fov},
    near_plane{near_plane} {}


/* Scene object definitions */

// Sphere
Sphere::Sphere(Vec3 origin, Vec3 radius) : origin{origin}, radius{radius} {}

float Sphere::RayCollision(const Ray& r) const {
    float result = std::numeric_limits<float>::infinity();
    // TODO: implement line-sphere collision
    return result;
}