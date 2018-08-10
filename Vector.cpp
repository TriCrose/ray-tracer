#include <cmath>

#include "Vector.h"

// Construcors
Vec3::Vec3() : x{0.0f}, y{0.0f}, z{0.0f} {}
Vec3::Vec3(float f) : x{f}, y{f}, z{f} {}
Vec3::Vec3(float x, float y, float z) : x{x}, y{y}, z{z} {}

// Arithmetic operators
const Vec3& Vec3::operator+(const Vec3& v) const { return { x + v.x, y + v.y, z + v.z }; }
const Vec3& Vec3::operator-(const Vec3& v) const { return { x - v.x, y - v.y, z - v.z }; }
const Vec3& Vec3::operator*(const Vec3& v) const { return { x * v.x, y * v.y, z * v.z }; }
const Vec3& Vec3::operator/(const Vec3& v) const { return { x / v.x, y / v.y, z / v.z }; }
const Vec3& Vec3::operator*(float f) const { return { x * f, y * f, z * f }; }
const Vec3& Vec3::operator/(float f) const { return { x / f, y / f, z / f }; }

const Vec3& Vec3::operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
const Vec3& Vec3::operator-=(const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
const Vec3& Vec3::operator*=(const Vec3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
const Vec3& Vec3::operator/=(const Vec3& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }
const Vec3& Vec3::operator*=(float f) { x *= f; y *= f; z *= f; return *this; }
const Vec3& Vec3::operator/=(float f) { x /= f; y /= f; z /= f; return *this; }

const Vec3& operator*(float f, const Vec3& v) { return v * f; }
const Vec3& operator/(float f, const Vec3& v) { return { f / v.x, f / v.y, f / v.z }; }

// Products
float Vec3::Dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
const Vec3& Vec3::Cross(const Vec3& v) const { return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };  }

// Normalization
float Vec3::GetLength() const { return sqrt(x*x + y*y + z*z); }
void Vec3::Normalize() { *this /= GetLength(); }
const Vec3& Vec3::GetNormalized() const { return *this / GetLength(); }