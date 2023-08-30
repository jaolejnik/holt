#include "clear.h"
#include "../color.h"
#include "../utils.h"

#include <glm/glm.hpp>

namespace holt
{

bool Clear::scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const
{
    attenuation           = Color(1.0f);
    float refractionRatio = hitRecord.frontFace ? 1.0f / mRefractionIndex : mRefractionIndex;

    auto unitDirection = glm::normalize(inRay.direction);
    float cosTheta     = glm::min(glm::dot(-unitDirection, hitRecord.normal), 1.0f);
    float sinTheta     = glm::sqrt(1.0f - cosTheta * cosTheta);

    bool cannotRefract = refractionRatio * sinTheta > 1.0f;
    auto direction     = (cannotRefract || reflectance(cosTheta, refractionRatio) > random())
                             ? glm::reflect(unitDirection, hitRecord.normal)
                             : glm::refract(unitDirection, hitRecord.normal, refractionRatio);

    scatteredRay = Ray(hitRecord.point, direction);

    return true;
}

float Clear::reflectance(float cosTheta, float refractionRatio) // Schlick's approximation for reflectance.
{
    float r0 = (1.0f - refractionRatio) / (1.0f + refractionRatio);
    r0       = r0 * r0;

    return r0 + (1.0f - r0) * glm::pow(1.0f - cosTheta, 5);
}

}; // namespace holt
