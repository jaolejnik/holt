#include "metal.h"
#include "../utils.h"

#include <glm/glm.hpp>

namespace holt
{

bool Metal::scatter(Ray &ray, const HitRecord &hitRecord, Color &attenuation) const
{
    auto reflectDirection = glm::reflect(glm::normalize(ray.direction), hitRecord.normal);
    ray.origin            = hitRecord.point;
    ray.direction         = reflectDirection + mFuzz * randomUnitVec3();
    attenuation           = mAlbedo;

    return glm::dot(ray.direction, hitRecord.normal) > 0.0f;
}

}; // namespace holt
