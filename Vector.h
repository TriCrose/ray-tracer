#ifndef VECTOR_H
#define VECTOR_H
#pragma once

class Vec3 {
public:
    // Constructors
    Vec3();
    Vec3(float);
    Vec3(float, float, float);

    // Arithmetic operators
    const Vec3& operator+(const Vec3&) const;
    const Vec3& operator-(const Vec3&) const;
    const Vec3& operator*(const Vec3&) const;
    const Vec3& operator/(const Vec3&) const;
    const Vec3& operator*(float) const;
    const Vec3& operator/(float) const;

    const Vec3& operator+=(const Vec3&);
    const Vec3& operator-=(const Vec3&);
    const Vec3& operator*=(const Vec3&);
    const Vec3& operator/=(const Vec3&);
    const Vec3& operator*=(float);
    const Vec3& operator/=(float);

    // Products
    float Dot(const Vec3&) const;
    const Vec3& Cross(const Vec3&) const;

    // Normalisation
    float GetLength() const;
    void Normalize();
    const Vec3& GetNormalized() const;

    float x, y, z;
};

// Can't be defined in Vec3 since the float is on the left
const Vec3& operator*(float, const Vec3&);
const Vec3& operator/(float, const Vec3&);

#endif // VECTOR_H