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

        bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const override;
    };
}
