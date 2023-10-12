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
    glm::vec3 mForward;
    glm::vec3 mRight;
    glm::vec3 mUp;
    glm::vec3 mClipPlaneParams;

  public:
    void update(float aspectRatio);

    const glm::vec3 &getForward() const { return mForward; }
    const glm::vec3 &getRight() const { return mRight; }
    const glm::vec3 &getUp() const { return mUp; }
    const glm::vec3 &getClipPlaneParams() const { return mClipPlaneParams; }
};

} // namespace holt
