#pragma once

#include "color.h"
#include "ray.h"

#include <glm/vec3.hpp>

namespace holt
{

class Camera
{
  public:
    float FOVDegrees      = 90.0f;
    float focusDistance   = 1.0f;
    float defocusStrength = 0.0f;

    glm::vec3 lookAt   = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 1.0f);

  private:
    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 clipPlaneParams;

  public:
    void update(float aspectRatio);

    const glm::vec3 &getForward() const { return forward; }
    const glm::vec3 &getRight() const { return right; }
    const glm::vec3 &getUp() const { return up; }
    const glm::vec3 &getClipPlaneParams() const { return clipPlaneParams; }
};

} // namespace holt
