#pragma once

#include "material.h"

namespace holt
{
    class Clear : public Material
    {
    private:
        float m_refractionIndex;

        static float reflectance(float cosTheta, float refractionRatio);

    public:
        Clear(float refractionIndex) : m_refractionIndex(refractionIndex) {}

        bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const override;
    };
}