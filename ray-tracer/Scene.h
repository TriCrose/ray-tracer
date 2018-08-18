#pragma once
#ifndef OBJECTS_H
#define OBJECTS_H

#include "Ray.h"

namespace Scene {

class Camera {
public:
    // fov is in degrees
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
    virtual float RayCollision(const Ray&) const = 0;
};

class Sphere : public Object {
public:
    Sphere(Vec3 origin, float radius);

    float RayCollision(const Ray& r) const;

    Vec3 origin;
    float radius;
};

} // namespace Scene

#endif // OBJECT_H