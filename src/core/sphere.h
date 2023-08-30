#pragma once

#include "hittable.h"

#include <glm/vec3.hpp>
#include <memory>

namespace holt
{

class Sphere : public Hittable
{
  private:
    glm::vec3 mCenter;
    float mRadius;
    std::shared_ptr<Material> mMaterial;

  public:
    Sphere(glm::vec3 center, float radius, std::shared_ptr<Material> material)
        : mCenter(center), mRadius(radius), mMaterial(material)
    {
    }

    bool hit(const Ray &ray, Interval rayT, HitRecord &hitRecord) const override;
};

} // namespace holt
