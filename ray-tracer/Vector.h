#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

class Vec3 {
public:
    // Constructors
    Vec3(): x{0.0f}, y{0.0f}, z{0.0f} {}
    Vec3(float f) : x{f}, y{f}, z{f} {}
    Vec3(float x, float y, float z) : x{x}, y{y}, z{z} {}

    // Arithmetic operators
    Vec3 operator+(const Vec3& v) const { return { x + v.x, y + v.y, z + v.z }; }
    Vec3 operator-(const Vec3& v) const { return { x - v.x, y - v.y, z - v.z }; }
    Vec3 operator-() const { return { -x, -y, -z }; }
    Vec3 operator*(const Vec3& v) const { return { x * v.x, y * v.y, z * v.z }; }
    Vec3 operator/(const Vec3& v) const { return { x / v.x, y / v.y, z / v.z }; }
    Vec3 operator*(float f) const { return { x * f, y * f, z * f }; }
    Vec3 operator/(float f) const { return { x / f, y / f, z / f }; }

    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    Vec3& operator-=(const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
    Vec3& operator*=(const Vec3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
    Vec3& operator/=(const Vec3& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }
    Vec3& operator*=(float f) { x *= f; y *= f; z *= f; return *this; }
    Vec3& operator/=(float f) { x /= f; y /= f; z /= f; return *this; }

    // Products
    float Dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3 Cross(const Vec3& v) const { return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x }; }

    // Normalisation
    float Length() const { return std::sqrtf(x*x + y*y + z*z); }
    float LengthSquared() const { return x*x + y*y + z*z; }
    Vec3 Normalized() const { return *this / Length(); }

    float x, y, z;
};

// Can't be defined in Vec3 since the float is on the left
inline Vec3 operator*(float f, const Vec3& v) { return v * f; }
inline Vec3 operator/(float f, const Vec3& v) { return { f / v.x, f / v.y, f / v.z }; }

// Output stream
inline std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
    stream << "Vec3{" << v.x << ", " <<
                         v.y << ", " <<
                         v.z << "}";
    return stream;
}

#endif // VECTOR_H