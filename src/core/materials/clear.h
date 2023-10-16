#pragma once

#include "material.h"

namespace holt
{

class Clear : public Material
{
  private:
    float mRefractionIndex;

    static float reflectance(float cosTheta, float refractionRatio);

  public:
    Clear(float refractionIndex) : mRefractionIndex(refractionIndex) {}

    bool scatter(Ray &ray, const HitRecord &hitRecord, Color &attenuation) const override;
};

} // namespace holt
