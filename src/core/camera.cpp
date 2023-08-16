#include "camera.h"

#include <glm/glm.hpp>

namespace holt
{
    Camera::Camera(glm::vec3 position, const glm::vec3 &origin)
        : m_position(position)
    {
        m_forward = glm::normalize(origin - m_position);
        m_right = glm::normalize(glm::cross(m_forward, glm::vec3(0.0f, 1.0f, 0.0f)));
        m_up = glm::normalize(glm::cross(m_right, m_forward));
    }

    const glm::vec3 Camera::rayDirection(const glm::vec2 &point)
    {
        return glm::normalize(point.x * m_right + point.y * m_up + 1.5f * m_forward);
    }
} // namespace holt
