#pragma once
#ifndef OBJECTS_H
#define OBJECTS_H

#include "Ray.h"

namespace Scene {

class Camera {
public:
    // fov is in radians
    Camera(int image_width, int image_height, float near_plane);
    Camera(int image_width, int image_height, Vec3 position, Vec3 dir, float fov, float near_plane);

    int image_width;
    int image_height;
    Vec3 position;
    Vec3 dir;
    float fov;
    float near_plane;
};

class Light {
public:
    Light(Vec3 position);
    Light(Vec3 position, Vec3 colour);

    Vec3 position;
    Vec3 colour;
};

class Object {
public:
    // Returns the distance along the ray to the collision (or infinity if there is no collision)
    virtual float RayCollision(const Ray&) const = 0;

    static constexpr float epsilon = 0.01f;
    static constexpr float infinity = std::numeric_limits<float>::infinity();
};

class Sphere : public Object {
public:
    Sphere(Vec3 origin, float radius);

    float RayCollision(const Ray& r) const override;

    Vec3 origin;
    float radius;
};

} // namespace Scene

#endif // OBJECT_H