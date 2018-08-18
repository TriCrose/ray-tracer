#pragma once
#ifndef RAY_H
#define RAY_H

#include "Vector.h"

class Ray {
public:
    Ray(Vec3 origin, Vec3 dir) : origin{origin}, dir{dir.Normalized()} {}

    Vec3 Along(float dist) const { return origin + dist * dir; }

    Vec3 origin;
    Vec3 dir;
};

#endif // RAY_H