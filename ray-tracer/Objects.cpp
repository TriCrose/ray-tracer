#include "Objects.h"

using namespace Scene;

/* Sphere */

Sphere::Sphere(Vec3 origin, Vec3 radius) : origin{origin}, radius{radius} {}
Vec3 Sphere::Origin() const { return origin; }
Vec3 Sphere::Radius() const { return radius; }

float Sphere::RayCollision(const Ray& r) const {
    float result = std::numeric_limits<float>::infinity();
    // TODO
    return result;
}