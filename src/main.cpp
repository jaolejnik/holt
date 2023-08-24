#include "core/bitmap.h"
#include "core/camera.h"
#include "core/ray.h"
#include "core/hittable.h"
#include "core/hittableList.h"
#include "core/sphere.h"
#include "core/interval.h"
#include "core/materials/materials.h"

#include <glm/glm.hpp>
#include <memory>

int main()
{
    const glm::vec3 origin = glm::vec3(0.0f);
    const glm::vec2 resolution{1024, 768};

    holt::Camera camera(
        glm::vec3(0.0f, 0.0f, 1.0f),
        origin,
        resolution,
        3);

    auto ground = std::make_shared<holt::Diffuse>(holt::Color(0.7, 0.7, 0.2));
    auto red = std::make_shared<holt::Diffuse>(holt::Color(0.7, 0.3, 0.3));
    auto silver = std::make_shared<holt::Metal>(holt::Color(0.8, 0.8, 0.8), 0.00f);
    auto gold = std::make_shared<holt::Metal>(holt::Color(0.8, 0.6, 0.2), 0.8f);
    auto glass = std::make_shared<holt::Clear>(1.5f);

    holt::HittableList world;
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, -100.5f, -1.0), 100.0f, ground));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, 0.0f, -1.0), 0.5f, red));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(-1.0f, 0.0f, -1.0), 0.5f, glass));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(1.0f, 0.0f, -1.0), 0.5f, gold));

    camera.render(world);
    camera.saveFrame("out.png");

    return 0;
}
