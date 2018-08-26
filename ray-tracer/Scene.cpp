#include <algorithm>
#include "Bitmap.h"

#include "Scene.h"

// Scene

Scene::Scene(int image_width, int image_height, float fov) :
    width{image_width},
    height{image_height},
    fov{fov} {
}

void Scene::CreateLight(const Vec3& pos, const Vec3& colour) {
    lights.push_back({pos, colour});
}

void Scene::AddObject(const Object* obj) {
    objects.push_back(obj);
}

bool Scene::Render(const std::string& filename) const {
    Bitmap output {width, height};
    // TODO
    return output.WriteToDisk(filename);
}

// Objects

Sphere::Sphere(Vec3 origin, float radius) : origin{ origin }, radius{ radius } {
}

float Sphere::RayCollision(const Ray& r) const {
    // Quadratic equation (a is 1)
    Vec3 diff { r.origin - origin };
    float b { 2 * diff.Dot(r.dir) };
    float c { diff.LengthSquared() - radius * radius };
    float discriminant { b * b - 4 * c };

    if (discriminant < 0.0f) {
        return Object::kInfinity;
    } else if (discriminant < Object::kEpsilon) {
        return b > 0.0f ? Object::kInfinity : -b;
    } else {
        float s { std::sqrtf(discriminant) };
        float one { -b + s };
        float two { -b - s };

        if (one < 0.0f && two < 0.0f) return Object::kInfinity;
        else if (one < 0.0f) return two;
        else if (two < 0.0f) return one;
        else return std::min(one, two);
    }
}

Vec3 Sphere::Normal(const Vec3& pos) const {
    return (pos - origin).Normalized();
}