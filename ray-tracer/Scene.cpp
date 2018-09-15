#include <algorithm>
#include "Bitmap.h"
#include "Utils.h"

#include "Scene.h"

// Scene

Scene::Scene(int image_width, int image_height, float fov) :
    width   {image_width},
    height  {image_height},
    fov     {fov}
{
}

void Scene::SetLight(const Vec3& pos, const Vec3& colour) {
    light.first = pos;
    light.second = colour;
}

void Scene::AddObject(const Object* obj) {
    objects.push_back(obj);
}

bool Scene::Render(const std::string& filename) const {
    Bitmap output {width, height};
    
    float aspect {static_cast<float>(width)/static_cast<float>(height)};
    Vec3 camera_location {0.0f, 0.0f, 0.5f * aspect / std::tanf(0.5f * fov)};

    for (int i {0}; i < width; i++) {
        float hor_proportion {static_cast<float>(i)/static_cast<float>(width)};

        for (int j {0}; j < height; j++) {
            float vert_proportion {static_cast<float>(j)/static_cast<float>(height)};
            Vec3 pixel_location {aspect * (hor_proportion - 0.5f), vert_proportion - 0.5f, 0.0f};
            
            Ray r {camera_location, (pixel_location - camera_location).Normalized()};
            float closest_dist {Utils::kInfinity};
            const Object* closest_obj {nullptr};

            for (auto obj : objects) {
                float dist {obj->RayCollision(r)};
                if (dist < closest_dist) {
                    closest_dist = dist;
                    closest_obj = obj;
                }
            }

            if (closest_obj) {
                Vec3 point {r.Along(closest_dist)};
                Vec3 light_ray {(light.first - point).Normalized()};

                Vec3 ambient {0.02f, 0.02f, 0.02f};
                Vec3 diffuse {};
                Vec3 specular {};

                if (closest_obj->RayCollision({point, light_ray}) == Utils::kInfinity) {
                    diffuse = Vec3{std::max(closest_obj->Normal(point).Dot(light_ray), 0.0f)};
                }

                output.SetPixel(i, j, (ambient + diffuse + specular).Clamped());
            }
        }
    }

    return output.WriteToDisk(filename);
}

// Objects

Sphere::Sphere(Vec3 origin, float radius) : origin{origin}, radius{radius} {
}

float Sphere::RayCollision(const Ray& r) const {
    // Quadratic equation (a is 1)
    Vec3 diff {r.origin - origin};
    float b {2 * diff.Dot(r.dir)};
    float c {diff.LengthSquared() - radius * radius};
    float discriminant {b * b - 4 * c};

    if (discriminant < 0.0f) {
        return Utils::kInfinity;
    } else if (discriminant < Utils::kEpsilon) {
        return b > 0.0f ? Utils::kInfinity : -b;
    } else {
        float s {std::sqrtf(discriminant)};
        float one {-b + s};
        float two {-b - s};

        if (one < 0.0f && two < 0.0f) return Utils::kInfinity;
        else if (one < 0.0f) return two;
        else if (two < 0.0f) return one;
        else return std::min(one, two);
    }
}

Vec3 Sphere::Normal(const Vec3& pos) const {
    return (pos - origin).Normalized();
}