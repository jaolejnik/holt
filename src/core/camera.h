#pragma once

#include "bitmap.h"
#include "color.h"
#include "hittable.h"
#include "ray.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace holt
{

class Camera
{
  public:
    int samplingRate = 3;
    int maxDepth = 10;

    float FOVDegrees = 90.0f;
    float focusDistance = 1.0f;
    float defocusStrength = 0.0f;

    glm::vec3 lookAt = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 1.0f);

  private:
    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 clipPlaneParams;

    Color background = Color(0.0f);
    Bitmap frame;

  public:
    Camera(const glm::vec2 &resolution) : frame(resolution) {}

    void update();
    Ray getRay(const glm::vec2 &point) const;
    const Color traceRay(const Ray &ray, const Hittable &world, int depth) const;
    void render(const Hittable &world);
    void saveFrame(const std::string &outPath) const { frame.save(outPath); }
};

} // namespace holt
