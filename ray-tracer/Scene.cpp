#include <algorithm>

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
Sphere::Sphere(Vec3 origin, float radius) : origin{ origin }, radius{ radius } {}

float Sphere::RayCollision(const Ray& r) const {
    // Quadratic equation (a is 1)
    Vec3 diff { r.origin - origin };
    float b { 2 * diff.Dot(r.dir) };
    float c { diff.LengthSquared() - radius * radius };
    float discriminant { b * b - 4 * c };

    if (discriminant < 0.0f) {
        return infinity;
    } else if (discriminant < epsilon) {
        return b > 0.0f ? infinity : -b;
    } else {
        float s { std::sqrtf(discriminant) };
        float one { -b + s };
        float two { -b - s };

        if (one < 0.0f && two < 0.0f) return infinity;
        else if (one < 0.0f) return two;
        else if (two < 0.0f) return one;
        else return std::min(one, two);
    }
}