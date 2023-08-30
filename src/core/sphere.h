#pragma once

#include "hittable.h"

#include <glm/vec3.hpp>
#include <memory>

namespace holt
{

class Sphere : public Hittable
{
  public:
    glm::vec3 center;
    float radius;
    std::shared_ptr<Material> material;

    Sphere(glm::vec3 center, float radius, std::shared_ptr<Material> material)
        : center(center), radius(radius), material(material)
    {
    }

    bool hit(const Ray &ray, Interval rayT, HitRecord &hitRecord) const override;
};

} // namespace holt
