#include "camera.h"
#include "interval.h"

#include <glm/glm.hpp>
#include <iostream>

namespace holt
{
    Camera::Camera(glm::vec3 position, const glm::vec3 &origin, const glm::vec2 &resolution)
        : m_position(position), m_frame(resolution)
    {
        m_forward = glm::normalize(origin - m_position);
        m_right = glm::normalize(glm::cross(m_forward, glm::vec3(0.0f, 1.0f, 0.0f)));
        m_up = glm::normalize(glm::cross(m_right, m_forward));
    }

    const glm::vec3 Camera::rayDirection(const glm::vec2 &point) const
    {
        return point.x * m_right + point.y * m_up + 1.5f * m_forward;
    }

    const Color Camera::rayColor(const holt::Ray &ray, const holt::Hittable &world) const
    {
        HitRecord hitRecord;
        if (world.hit(ray, holt::Interval(0.0f, holt::infinity), hitRecord))
            return 0.5f * (hitRecord.normal + holt::Color(1.0f));

        auto unitDirection = glm::normalize(ray.direction());
        auto a = 0.5f * (unitDirection.y + 1.0f);
        auto cf = (1.0f - a) * holt::Color(1.0f) + a * holt::Color(0.3f, 0.5f, 1.0f);

        return cf;
    }

    void Camera::render(const Hittable &world)
    {
        for (int y = m_frame.height() - 1; y >= 0; y--)
        {
            std::cout << "\rScanlines remaining: " << y << ' ' << std::flush;
            for (int x = 0; x < m_frame.width(); x++)
            {
                auto p = (2.0f * glm::vec2(x, y) - m_frame.resolution()) / static_cast<float>(m_frame.height());
                holt::Ray ray(m_position, rayDirection(p));
                auto color = rayColor(ray, world);

                m_frame.setPixel(x, m_frame.height() - 1 - y, color);
            }
        }
        std::cout << "\nDone!\n";
    }
} // namespace holt
