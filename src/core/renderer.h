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
    Color mBackground                = Colors::BLACK;
    const glm::ivec2 mTileResolution = glm::vec2(32, 32);
    const int mAvailableCores;
    TileQueue mTiles;
    Bitmap mFrame;

  public:
    Renderer(const glm::vec2 &resolution);

    const Color traceRay(const Ray &ray, const Hittable &world, int depth) const;
    void render(const Camera &camera, const Hittable &world);

    const float frameAspectRatio() const { return mFrame.aspectRatio(); }
    void saveFrame(const std::string &outPath) const { mFrame.save(outPath); }

  private:
    Ray getRay(const Camera &camera, const glm::vec2 &point) const;
};

} // namespace holt
