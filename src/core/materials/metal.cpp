#include "metal.h"
#include "../utils.h"

#include <glm/glm.hpp>

namespace holt
{
    bool Metal::scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const
    {
        auto reflectDirection = glm::reflect(glm::normalize(inRay.direction()), hitRecord.normal);
        scatteredRay = Ray(hitRecord.point, reflectDirection + m_fuzz * randomUnitVec3());
        attenuation = m_albedo;

        return glm::dot(scatteredRay.direction(), hitRecord.normal) > 0.0f;
    }
};
