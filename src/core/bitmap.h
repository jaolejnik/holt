#pragma once

#include "color.h"

#include <glm/vec2.hpp>
#include <string>
#include <vector>

namespace holt
{

class Bitmap
{
  public:
    const size_t width;
    const size_t height;

  private:
    std::vector<Pixel> pixels;

  public:
    Bitmap(glm::vec2 resolution, const Color &color = Colors::BLACK);

    void clear();
    void fill(const Color &color);
    void setPixel(size_t x, size_t y, const Color &color);
    void setPixel(size_t i, const Color &color);
    bool load(const std::string &imgPath);
    bool save(const std::string &outPath) const;

    const float widthF() const { return static_cast<float>(width); }
    const float heightF() const { return static_cast<float>(height); }
    const float aspectRatio() const { return static_cast<float>(width) / static_cast<float>(height); }
    const glm::vec2 resolution() const { return {width, height}; }
};

} // namespace holt
