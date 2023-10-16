#include "diffuse.h"
#include "../utils.h"

namespace holt
{

bool Diffuse::scatter(Ray &ray, const HitRecord &hitRecord, Color &attenuation) const
{
    auto scatterDirection = hitRecord.normal + randomUnitVec3();

    if (isAlmostZero(scatterDirection))
        scatterDirection = hitRecord.normal;

    ray.origin    = hitRecord.point;
    ray.direction = scatterDirection;
    attenuation   = mAlbedo;

    return true;
}

}; // namespace holt
