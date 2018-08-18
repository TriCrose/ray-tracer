#include "Renderer.h"
#include "Bitmap.h"

bool Renderer::Render(const Scene::Camera& camera,
                      const Scene::Light& light,
                      const std::vector<const Scene::Object*>& scene_objects,
                      const std::string& bmp_filename)
{
    Bitmap output {camera.image_width, camera.image_height};
    // TODO: write rendering algorithm
    return output.WriteToDisk(bmp_filename);
}