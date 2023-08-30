#include "core/camera.h"
#include "core/hittableList.h"
#include "core/materials/materials.h"
#include "core/sphere.h"

#include <glm/glm.hpp>
#include <memory>

int main()
{
    auto ground = std::make_shared<holt::Diffuse>(holt::Color(0.5f, 0.5f, 0.5f));
    auto sun = std::make_shared<holt::DiffuseLight>(holt::Color(0.6f, 0.6f, 0.8f), 2.0f);
    auto lightBlue = std::make_shared<holt::DiffuseLight>(holt::Color(0.4f, 0.8f, 0.4f), 10.0f);
    auto lightGreen = std::make_shared<holt::DiffuseLight>(holt::Color(0.4f, 0.4f, 0.8f), 10.0f);
    auto red = std::make_shared<holt::Diffuse>(holt::Color(0.7f, 0.3f, 0.3f));
    auto silver = std::make_shared<holt::Metal>(holt::Color(0.8f, 0.8f, 0.8f), 0.0f);
    auto gold = std::make_shared<holt::Metal>(holt::Color(0.8f, 0.6f, 0.2f), 0.8f);
    auto glass = std::make_shared<holt::Clear>(1.5f);

    holt::HittableList world;
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, -100.5f, -1.0), 100.0f, ground));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, 80.0f, 0.0f), 40.0f, sun));

    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, 0.0f, -1.0f), 0.5f, red));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(-0.5f, -0.35f, -0.35f), 0.15f, lightBlue));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.5f, -0.35f, -0.35f), 0.15f, lightGreen));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(-1.0f, 0.0f, -1.0f), 0.5f, glass));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(-1.0f, 0.0f, -1.0f), -0.45f, glass));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(1.0f, 0.0f, -1.0f), 0.5f, silver));

    holt::Camera camera({1024, 768});
    camera.position = glm::vec3(-1.0f, 1.5f, 2.0f);
    camera.lookAt = glm::vec3(0.0f, 0.0f, -1.0f);
    camera.FOVDegrees = 40.0f;
    camera.focusDistance = 3.4f;
    camera.defocusStrength = 25.0f;

    camera.update();
    camera.render(world);
    camera.saveFrame("out.png");

    return 0;
}
