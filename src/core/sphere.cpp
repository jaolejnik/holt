#include "sphere.h"

#include <glm/glm.hpp>

namespace holt
{
    bool Sphere::hit(const Ray &ray, Interval rayT, HitRecord &hitRecord) const
    {
        auto rd = ray.direction();
        auto oc = ray.origin() - m_center;
        auto rdLen = glm::length(rd);
        auto ocLen = glm::length(oc);

        auto a = rdLen * rdLen;
        auto halfB = glm::dot(oc, rd);
        auto c = ocLen * ocLen - m_radius * m_radius;
        auto discriminant = halfB * halfB - a * c;

        if (discriminant < 0.0f)
            return false;

        auto sqrtd = glm::sqrt(discriminant);
        auto rootd = (-halfB - glm::sqrt(discriminant)) / a;

        if (!rayT.surrounds(rootd))
        {
            auto rootd = (-halfB + glm::sqrt(discriminant)) / a;
            if (!rayT.surrounds(rootd))
                return false;
        }

        hitRecord.t = rootd;
        hitRecord.point = ray.at(hitRecord.t);
        auto outwardNormal = (hitRecord.point - m_center) / m_radius;
        hitRecord.setFaceNormal(ray, outwardNormal);
        hitRecord.material = m_material;

        return true;
    }
}
