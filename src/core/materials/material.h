#pragma once

#include "../color.h"
#include "../hittable.h"
#include "../ray.h"

namespace holt
{
class Material
{
  public:
    virtual ~Material() = default;

    virtual bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const = 0;

    virtual const Color emit() const { return Color(0.0f); }
};
} // namespace holt
