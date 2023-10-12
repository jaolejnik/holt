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
    mClipPlaneParams  = glm::vec3(planeWidth, planeHeight, focusDistance);

    mForward = glm::normalize(lookAt - position);
    mRight   = glm::normalize(glm::cross(mForward, glm::vec3(0.0f, 1.0f, 0.0f)));
    mUp      = glm::normalize(glm::cross(mRight, mForward));
}

} // namespace holt
