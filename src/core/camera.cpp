#include "camera.h"
#include "utils.h"

#include <glm/glm.hpp>
#include <iostream>

namespace holt
{

void Camera::update(float aspectRatio)
{
    float planeHeight = focusDistance * glm::tan(glm::radians(FOVDegrees) / 2.0f) * 2.0f;
    float planeWidth  = planeHeight * aspectRatio;
    clipPlaneParams   = glm::vec3(planeWidth, planeHeight, focusDistance);

    forward = glm::normalize(lookAt - position);
    right   = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
    up      = glm::normalize(glm::cross(right, forward));
}

} // namespace holt
