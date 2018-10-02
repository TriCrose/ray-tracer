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

void Scene::AddObject(std::unique_ptr<Object> obj) {
    objects.push_back(std::move(obj));
}

void Scene::Render(const std::string& filename) const {
    auto output = Bitmap{width, height};
    std::cout << "Created blank " << width << "x" << height << " bitmap image.\n";

    auto aspect = static_cast<float>(width)/static_cast<float>(height);
    auto camera_location = Vec3{0.0f, 0.0f, 0.5f * aspect / std::tanf(0.5f * fov)};

    std::cout << "Rendering... ";
    auto render_time = Utils::Time();

    for (auto i = 0; i < width; i++) {
        auto hor_proportion = static_cast<float>(i)/static_cast<float>(width);

        for (auto j = 0; j < height; j++) {
            auto vert_proportion = static_cast<float>(j)/static_cast<float>(height);
            auto pixel_location = Vec3{aspect * (hor_proportion - 0.5f), vert_proportion - 0.5f, 0.0f};

            auto r = Ray{camera_location, (pixel_location - camera_location).Normalized()};
            auto closest_dist = Utils::kInfinity;
            auto closest_index = -1;

            for (auto k = unsigned{0}; k < objects.size(); k++) {
                auto dist = objects[k]->RayCollision(r);
                if (dist < closest_dist) {
                    closest_dist = dist;
                    closest_index = k;
                }
            }

            if (closest_index != -1) {
                auto point = Vec3{r.Along(closest_dist - Utils::kEpsilon)};
                auto light_vector = Vec3{(light.first - point).Normalized()};
                auto normal = Vec3{objects[closest_index]->Normal(point)};

                auto eye_vector = Vec3{(camera_location - point).Normalized()};
                auto reflected = Vec3{light_vector.Reflected(normal)};
                auto spec_coefficient = 100.0f;

                auto ambient = Vec3{0.02f, 0.02f, 0.02f};
                auto diffuse = Vec3{};
                auto specular = Vec3{};

                if (objects[closest_index]->RayCollision({point, light_vector}) == Utils::kInfinity) {
                    diffuse = Vec3{std::max(normal.Dot(light_vector), 0.0f)};
                    diffuse *= light.second;
                    specular = Vec3{std::powf(std::max(reflected.Dot(eye_vector), 0.0f), spec_coefficient)};
                }

                output.SetPixel(i, j, (ambient + diffuse + specular).Clamped());
            }
        }
    }

    render_time = Utils::Time() - render_time;
    std::cout << "done.\nRender took " << render_time << " ms.\n";

    if (output.WriteToDisk(filename)) std::cout << "Saved image to " << filename << ".\n";
    else std::cout << "Failed to open file " << filename << " for writing.\n";
}

// Objects

Sphere::Sphere(Vec3 origin, float radius) : origin{origin}, radius{radius} {
}

float Sphere::RayCollision(const Ray& r) const {
    // Quadratic equation (a is 1)
    auto diff = Vec3{r.origin - origin};
    auto b = 2.0f * diff.Dot(r.dir);
    auto c = diff.LengthSquared() - radius * radius;
    auto discriminant = b * b - 4 * c;

    if (discriminant < 0.0f) {
        return Utils::kInfinity;
    } else if (discriminant < Utils::kEpsilon) {
        return b > 0.0f ? Utils::kInfinity : -b;
    } else {
        auto s = std::sqrtf(discriminant);
        if (s < b) return Utils::kInfinity;
        else if (s > -b) return (-b + s)/2.0f;
        else return (-b - s)/2.0f;
    }
}

Vec3 Sphere::Normal(const Vec3& pos) const {
    return (pos - origin).Normalized();
}