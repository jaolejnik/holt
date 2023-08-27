#pragma once

#include "material.h"
#include "../color.h"

namespace holt
{
    class Diffuse : public Material
    {
    private:
        Color mAlbedo;

    public:
        Diffuse(const Color &albedo) : mAlbedo(albedo) {}

        bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const override;
    };
}
