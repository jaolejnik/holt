#pragma once

#include "bitmap.h"
#include "color.h"
#include "ray.h"
#include "hittable.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace holt
{
    class Camera
    {
    private:
        int m_samplingRate = 3;
        glm::vec3 m_position;
        glm::vec3 m_forward;
        glm::vec3 m_right;
        glm::vec3 m_up;
        Bitmap m_frame;

    public:
        Camera(glm::vec3 position, const glm::vec3 &origin, const glm::vec2 &resolution, int samplingRate);

        const glm::vec3 rayDirection(const glm::vec2 &point) const;
        const Color rayColor(const Ray &ray, const Hittable &world) const;
        void render(const Hittable &world);

        void saveFrame(const std::string &outPath) const { m_frame.save(outPath); }
        const glm::vec3 position() const { return m_position; }
    };
} // namespace holt
