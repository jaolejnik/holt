#include "diffuse.h"
#include "../utils.h"

namespace holt
{

bool Diffuse::scatter(const Ray &inRay, const HitRecord &hitRecord, Color &attenuation, Ray &scatteredRay) const
{
    auto scatterDirection = hitRecord.normal + randomUnitVec3();

    if (isAlmostZero(scatterDirection)) scatterDirection = hitRecord.normal;

    scatteredRay = Ray(hitRecord.point, scatterDirection);
    attenuation = mAlbedo;

    return true;
}

}; // namespace holt
