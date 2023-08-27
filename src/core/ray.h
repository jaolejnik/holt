#pragma once

#include <glm/vec3.hpp>

namespace holt
{
    class Ray
    {
    private:
        glm::vec3 mOrigin;
        glm::vec3 mDirection;

    public:
        Ray() {}
        Ray(const glm::vec3 &rayOrigin, const glm::vec3 &rayDirection)
            : mOrigin(rayOrigin), mDirection(rayDirection) {}

        const glm::vec3 at(float t) const { return mOrigin + t * mDirection; }

        const glm::vec3 &origin() const { return mOrigin; }
        const glm::vec3 &direction() const { return mDirection; }
    };
} // namespace holt
