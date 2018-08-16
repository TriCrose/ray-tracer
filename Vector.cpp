#include "Vector.h"

#include <cmath>

// Construcors
Vec3::Vec3() : x{0.0f}, y{0.0f}, z{0.0f} {}
Vec3::Vec3(float f) : x{f}, y{f}, z{f} {}
Vec3::Vec3(float x, float y, float z) : x{x}, y{y}, z{z} {}

// Arithmetic operators
Vec3 Vec3::operator+(const Vec3& v) const { return { x + v.x, y + v.y, z + v.z }; }
Vec3 Vec3::operator-(const Vec3& v) const { return { x - v.x, y - v.y, z - v.z }; }
Vec3 Vec3::operator-() const { return { -x, -y, -z }; }
Vec3 Vec3::operator*(const Vec3& v) const { return { x * v.x, y * v.y, z * v.z }; }
Vec3 Vec3::operator/(const Vec3& v) const { return { x / v.x, y / v.y, z / v.z }; }
Vec3 Vec3::operator*(float f) const { return { x * f, y * f, z * f }; }
Vec3 Vec3::operator/(float f) const { return { x / f, y / f, z / f }; }

const Vec3& Vec3::operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
const Vec3& Vec3::operator-=(const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
const Vec3& Vec3::operator*=(const Vec3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
const Vec3& Vec3::operator/=(const Vec3& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }
const Vec3& Vec3::operator*=(float f) { x *= f; y *= f; z *= f; return *this; }
const Vec3& Vec3::operator/=(float f) { x /= f; y /= f; z /= f; return *this; }

Vec3 operator*(float f, const Vec3& v) { return v * f; }
Vec3 operator/(float f, const Vec3& v) { return { f / v.x, f / v.y, f / v.z }; }

// Products
float Vec3::Dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
Vec3 Vec3::Cross(const Vec3& v) const { return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };  }

// Normalization
float Vec3::Length() const { return sqrt(x*x + y*y + z*z); }
Vec3 Vec3::Normalized() const { return *this / Length(); }

// Output stream
std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
    stream << "Vec3{ " << v.x << ", " <<
                          v.y << ", " <<
                          v.z << " }";
    return stream;
}