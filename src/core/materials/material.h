#pragma once

#include "../ray.h"
#include "../color.h"
#include "../hittable.h"

namespace holt
{
    class Material
    {
    public:
        virtual ~Material() = default;

        virtual bool scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const = 0;
    };
} // namespace holt
