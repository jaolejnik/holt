#pragma once

#include "hittable.h"

#include <glm/vec3.hpp>
#include <memory>

namespace holt
{
    class Sphere : public Hittable
    {
    private:
        glm::vec3 m_center;
        float m_radius;
        std::shared_ptr<Material> m_material;

    public:
        Sphere(glm::vec3 center, float radius, std::shared_ptr<Material> material)
            : m_center(center), m_radius(radius), m_material(material) {}

        bool hit(const Ray &ray, Interval rayT, HitRecord &hitRecord) const override;
    };
} // namespace holt
