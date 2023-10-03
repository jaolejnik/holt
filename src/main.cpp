#include "core/camera.h"
#include "core/hittableList.h"
#include "core/materials/materials.h"
#include "core/renderer.h"
#include "core/sphere.h"
#include "core/utils.h"

#include <glm/vec3.hpp>

int main()
{
    // materials
    auto ground = std::make_shared<holt::Diffuse>(holt::Color(0.5f, 0.5f, 0.5f));
    auto sun    = std::make_shared<holt::DiffuseLight>(holt::Color(0.6f, 0.6f, 0.8f), 2.0f);
    auto glass  = std::make_shared<holt::Clear>(1.5f);
    auto silver = std::make_shared<holt::Metal>(holt::Color(0.8f, 0.8f, 0.8f), 0.0f);
    auto red    = std::make_shared<holt::Diffuse>(holt::Color(0.7f, 0.3f, 0.3f));

    // scene setup
    holt::HittableList world;
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, -500.0f, -1.0), 500.0f, ground));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, 80.0f, 0.0f), 40.0f, sun));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, 0.5f, 0.0f), 0.5f, red));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(-1.5f, 0.5f, 0.0f), 0.5f, glass));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(1.5f, 0.5f, 0.0f), 0.5f, silver));

    // add some random spheres
    for (float i = -11.0f; i < 11.0f; ++i)
    {
        for (float j = -11.0f; j < 11.0f; ++j)
        {
            auto center        = glm::vec3(i + 0.9f * holt::random(), 0.2f, j + 0.9f * holt::random());
            float randMaterial = holt::random();

            if (glm::length(center - glm::vec3(1.5f, 0.2f, 0.0f)) > 0.9f &&
                glm::length(center - glm::vec3(-1.5f, 0.2f, 0.0f)) > 0.9f &&
                glm::length(center - glm::vec3(0.0f, 0.2f, 0.0f)) > 0.9f)
            {
                std::shared_ptr<holt::Material> material;

                if (randMaterial < 0.6f)
                {
                    material = std::make_shared<holt::Diffuse>(holt::randomVec3() * holt::randomVec3());
                }
                else if (randMaterial < 0.85)
                {
                    auto emmisive  = holt::randomVec3() * holt::randomVec3();
                    float strength = holt::randomRange(8.0f, 12.0f);
                    material       = std::make_shared<holt::DiffuseLight>(emmisive, strength);
                }
                else if (randMaterial < 0.95)
                {
                    auto albedo = holt::randomVec3Range(0.5f, 1.0f);
                    float fuzz  = holt::randomRange(0.0f, 0.7f);
                    material    = std::make_shared<holt::Metal>(albedo, fuzz);
                }
                else
                {
                    material = glass;
                }

                world.add(std::make_shared<holt::Sphere>(center, 0.2f, material));
            }
        }
    }

    holt::Renderer renderer({1024, 768});
    // renderer.samplingRate = 23; // uncomment for nice quality and loooong rendering time

    holt::Camera camera;
    camera.position        = glm::vec3(-3.0f, 1.25f, 3.0f);
    camera.lookAt          = glm::vec3(-0.5f, 0.0f, 0.0f);
    camera.FOVDegrees      = 60.0f;
    camera.focusDistance   = 4.0f;
    camera.defocusStrength = 15.0f;

    camera.update(renderer.frameAspectRatio());
    renderer.render(camera, world);
    renderer.saveFrame("out.png");

    return 0;
}
