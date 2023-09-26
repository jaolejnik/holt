#pragma once

#include <glm/vec2.hpp>

namespace holt
{

class Rect
{
  public:
    int x;
    int y;
    int width;
    int height;

    Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {}
    Rect(const glm::ivec2 &coordinates, const glm::ivec2 &dimensions)
        : x(coordinates.x), y(coordinates.y), width(dimensions.x), height(dimensions.y)
    {
    }
};

} // namespace holt
