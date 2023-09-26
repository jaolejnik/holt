#pragma once

#include "bitmap.h"
#include "camera.h"
#include "color.h"
#include "hittable.h"
#include "ray.h"
#include "tileQueue.h"

#include <glm/vec2.hpp>

namespace holt
{

class Renderer
{
  public:
    int samplingRate = 3;
    int maxDepth     = 10;

  private:
    Color background                = Colors::BLACK;
    const glm::ivec2 tileResolution = glm::vec2(32, 32);
    const int availableCores;
    TileQueue tiles;
    Bitmap frame;

  public:
    Renderer(const glm::vec2 &resolution);

    const Color traceRay(const Ray &ray, const Hittable &world, int depth) const;
    void render(const Camera &camera, const Hittable &world);

    const float frameAspectRatio() const { return frame.aspectRatio(); }
    void saveFrame(const std::string &outPath) const { frame.save(outPath); }

  private:
    Ray getRay(const Camera &camera, const glm::vec2 &point) const;
};

} // namespace holt
