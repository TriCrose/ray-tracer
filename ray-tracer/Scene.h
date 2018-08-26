#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>

#include "Vector.h"

class Ray {
public:
    Ray(Vec3 origin, Vec3 dir) : origin{ origin }, dir{ dir.Normalized() } {}

    Vec3 Along(float dist) const { return origin + dist * dir; }

    Vec3 origin;
    Vec3 dir;
};

class Object {
public:
    virtual float RayCollision(const Ray&) const = 0;
    virtual Vec3 Normal(const Vec3&) const = 0;

    static constexpr float kEpsilon = 0.01f;
    static constexpr float kInfinity = std::numeric_limits<float>::infinity();
};

class Sphere : public Object {
public:
    Sphere(Vec3 origin, float radius);

    float RayCollision(const Ray& r) const override;
    Vec3 Normal(const Vec3& pos) const override;

    Vec3 origin;
    float radius;
};

class Scene {
    using Light = std::pair<Vec3, Vec3>;
public:
    Scene(int image_width, int image_height, float fov);

    void CreateLight(const Vec3& pos, const Vec3& colour = {1.0f});
    void AddObject(const Object* obj);

    bool Render(const std::string& filename) const;
private:
    std::vector<const Object*> objects;
    std::vector<Light> lights;

    int width;
    int height;
    float fov;
};

#endif // SCENE_H