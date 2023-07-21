#pragma once

#include <glm/vec3.hpp>

namespace holt
{
    class Ray
    {
    private:
        glm::vec3 m_origin;
        glm::vec3 m_direction;

    public:
        Ray(const glm::vec3 &rayOrigin, const glm::vec3 &rayDirection)
            : m_origin(rayOrigin), m_direction(rayDirection)
        {
        }

        const glm::vec3 at(float t) const { return m_origin + t * m_direction; }

        const glm::vec3 &origin() const { return m_origin; }
        const glm::vec3 &direction() const { return m_direction; }
    };
} // namespace holt