#include "core/bitmap.h"
#include "core/camera.h"
#include "core/ray.h"
#include "core/hittable.h"
#include "core/hittableList.h"
#include "core/sphere.h"
#include "core/interval.h"

#include <glm/glm.hpp>
#include <memory>

int main()
{
    const glm::vec3 origin = glm::vec3(0.0f);
    const glm::vec2 resolution{1024, 768};

    holt::Camera camera(
        glm::vec3(0.0f, 0.0f, 1.0f),
        origin,
        resolution);

    holt::HittableList world;
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, 0.0f, -1.0), 0.5f));
    world.add(std::make_shared<holt::Sphere>(glm::vec3(0.0f, -100.5f, -1.0), 100.0f));

    camera.render(world);
    camera.saveFrame("out.png");

    return 0;
}
