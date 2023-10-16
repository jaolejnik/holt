#pragma once

#include "../color.h"
#include "material.h"

namespace holt
{

class Diffuse : public Material
{
  private:
    Color mAlbedo;

  public:
    Diffuse(const Color &albedo) : mAlbedo(albedo) {}

    bool scatter(Ray &ray, const HitRecord &hitRecord, Color &attenuation) const override;
};

} // namespace holt
