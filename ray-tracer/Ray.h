#ifndef RAY_H
#define RAY_H
#pragma once

#include "Vector.h"

class Ray {
public:
    Ray(Vec3 origin, Vec3 dir) : origin{origin}, dir{dir.Normalized()} {}

    Vec3 Along(float dist) const { return origin + dist * dir; }
    Vec3 Origin() const  { return origin; }
    Vec3 Direction() const { return dir; }
private:
    const Vec3 origin;
    const Vec3 dir;
};

#endif // RAY_H