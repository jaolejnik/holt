#pragma once

#include "../color.h"
#include "material.h"

namespace holt
{
class DiffuseLight : public Material
{
  private:
    Color mEmmisive;
    float mEmmisionStrength;

  public:
    DiffuseLight(const Color &emmisive, float emmisionStrength = 1.0f)
        : mEmmisive(emmisive), mEmmisionStrength(emmisionStrength)
    {
    }

    bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const override
    {
        return false;
    }

    const Color emit() const override { return mEmmisive * mEmmisionStrength; }
};
} // namespace holt
