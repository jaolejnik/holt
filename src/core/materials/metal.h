#pragma once

#include "../color.h"
#include "material.h"

namespace holt
{

class Metal : public Material
{
  private:
    Color mAlbedo;
    float mFuzz;

  public:
    Metal(const Color &albedo, float fuzz) : mAlbedo(albedo), mFuzz(fuzz < 1.0f ? fuzz : 1.0f) {}

    bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const override;
};

} // namespace holt
