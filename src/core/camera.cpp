#include "camera.h"
#include "interval.h"
#include "utils.h"
#include "materials/material.h"

#include <glm/glm.hpp>
#include <iostream>

namespace holt
{
    Camera::Camera(glm::vec3 position, const glm::vec3 &origin, const glm::vec2 &resolution, int samplingRate)
        : m_position(position), m_frame(resolution), m_samplingRate(samplingRate)
    {
        m_forward = glm::normalize(origin - m_position);
        m_right = glm::normalize(glm::cross(m_forward, glm::vec3(0.0f, 1.0f, 0.0f)));
        m_up = glm::normalize(glm::cross(m_right, m_forward));
    }

    const glm::vec3 Camera::rayDirection(const glm::vec2 &point) const
    {
        return point.x * m_right + point.y * m_up + 1.5f * m_forward;
    }

    const Color Camera::traceRay(const holt::Ray &ray, const holt::Hittable &world, int depth) const
    {
        if (depth <= 0)
            return Color(0.0f);

        HitRecord hitRecord;
        if (world.hit(ray, holt::Interval(0.001f, holt::infinity), hitRecord))
        {
            Ray scatteredRay;
            Color attenuation;
            if (hitRecord.material->scatter(ray, hitRecord, attenuation, scatteredRay))
                return attenuation * traceRay(scatteredRay, world, depth - 1);
            return Color(0.0f);
        }

        auto unitDirection = glm::normalize(ray.direction());
        auto a = 0.5f * (unitDirection.y + 1.0f);
        auto cf = (1.0f - a) * holt::Color(1.0f) + a * holt::Color(0.3f, 0.5f, 1.0f);

        return cf;
    }

    void Camera::render(const Hittable &world)
    {
        for (int y = m_frame.height() - 1; y >= 0; --y)
        {
            std::cout << "\rScanlines remaining: " << y << ' ' << std::flush;
            for (int x = 0; x < m_frame.width(); ++x)
            {
                Color color(0.0f);
                auto pixelCoords = glm::vec2(x, y);

                for (float i = 0.0f; i < m_samplingRate; ++i)
                {
                    for (float j = 0.0f; j < m_samplingRate; ++j)
                    {
                        auto dv = (glm::vec2(i, j) + randomVec2()) / static_cast<float>(m_samplingRate);

                        auto p = (2.0f * (pixelCoords + dv) - m_frame.resolution()) / static_cast<float>(m_frame.height());
                        Ray ray(m_position, rayDirection(p));
                        color += traceRay(ray, world, m_maxDepth);
                    }
                }

                color *= 1.0f / (m_samplingRate * m_samplingRate);
                color = glm::sqrt(color);

                m_frame.setPixel(x, m_frame.height() - 1 - y, color);
            }
        }
        std::cout << "\nDone!\n";
    }
} // namespace holt
