#pragma once

#include "material.h"
#include "../color.h"

namespace holt
{
    class Diffuse : public Material
    {
    private:
        Color m_albedo;

    public:
        Diffuse(const Color &albedo) : m_albedo(albedo) {}

        bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const override;
    };
}
