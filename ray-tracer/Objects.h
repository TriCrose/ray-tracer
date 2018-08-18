#ifndef OBJECTS_H
#define OBJECTS_H
#pragma once

#include "Ray.h"

namespace Scene {

class Object {
public:
    virtual float RayCollision(const Ray&) const = 0;
};

class Sphere : public Object {
public:
    Sphere(Vec3 origin, Vec3 radius);

    Vec3 Origin() const;
    Vec3 Radius() const;

    float RayCollision(const Ray& r) const;
private:
    const Vec3 origin;
    const Vec3 radius;
};

} // namespace Scene

#endif // OBJECT_H