#pragma once

#include "hittable.h"

#include <glm/vec3.hpp>

namespace holt
{
    class Sphere : public Hittable
    {
    private:
        glm::vec3 m_center;
        float m_radius;

    public:
        Sphere(glm::vec3 center, float radius) : m_center(center), m_radius(radius) {}

        bool hit(const Ray &ray, Interval rayT, HitRecord &hitRecord) const override;
    };
} // namespace holt
