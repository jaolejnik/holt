#pragma once

#include <glm/vec3.hpp>

namespace holt
{

class Ray
{
  public:
    glm::vec3 origin;
    glm::vec3 direction;

    Ray() {}
    Ray(const glm::vec3 &rayOrigin, const glm::vec3 &rayDirection) : origin(rayOrigin), direction(rayDirection) {}

    const glm::vec3 at(float t) const { return origin + t * direction; }
};

} // namespace holt
