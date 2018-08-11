#ifndef VECTOR_H
#define VECTOR_H
#pragma once

#include <iostream>

class Vec3 {
public:
    // Constructors
    Vec3();
    Vec3(float);
    Vec3(float, float, float);

    // Arithmetic operators
    Vec3 operator+(const Vec3&) const;
    Vec3 operator-(const Vec3&) const;
    Vec3 operator-() const;
    Vec3 operator*(const Vec3&) const;
    Vec3 operator/(const Vec3&) const;
    Vec3 operator*(float) const;
    Vec3 operator/(float) const;

    const Vec3& operator+=(const Vec3&);
    const Vec3& operator-=(const Vec3&);
    const Vec3& operator*=(const Vec3&);
    const Vec3& operator/=(const Vec3&);
    const Vec3& operator*=(float);
    const Vec3& operator/=(float);

    // Products
    float Dot(const Vec3&) const;
    Vec3 Cross(const Vec3&) const;

    // Normalisation
    float Length() const;
    Vec3 Normalized() const;

    float x, y, z;
};

// Can't be defined in Vec3 since the float is on the left
Vec3 operator*(float, const Vec3&);
Vec3 operator/(float, const Vec3&);

// Output stream
std::ostream& operator<<(std::ostream&, const Vec3&);

#endif // VECTOR_H