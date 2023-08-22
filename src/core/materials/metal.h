#pragma once

#include "material.h"
#include "../color.h"

namespace holt
{
    class Metal : public Material
    {
    private:
        Color m_albedo;
        float m_fuzz;

    public:
        Metal(const Color &albedo, float fuzz) : m_albedo(albedo), m_fuzz(fuzz < 1.0f ? fuzz : 1.0f) {}

        bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const override;
    };
}
