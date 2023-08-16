#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace holt
{
    class Camera
    {
    private:
        glm::vec3 m_position;
        glm::vec3 m_forward;
        glm::vec3 m_right;
        glm::vec3 m_up;

    public:
        Camera(glm::vec3 position, const glm::vec3 &origin);

        const glm::vec3 rayDirection(const glm::vec2 &point);

        const glm::vec3 position() { return m_position; }
    };
} // namespace holt
