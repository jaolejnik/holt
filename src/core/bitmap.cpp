#include "bitmap.h"

#include <glm/glm.hpp>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image.h>
#include <stb_image_write.h>

namespace holt
{

Bitmap::Bitmap(glm::vec2 resolution, const Color &color) : width(resolution.x), height(resolution.y)
{
    pixels.resize(width * height);
    fill(color);
}

void Bitmap::clear() { fill(Colors::BLACK); }

void Bitmap::fill(const Color &color)
{
    for (Pixel &p : pixels)
        p = static_cast<Pixel>(color * 255.0f);
}

void Bitmap::setPixel(size_t x, size_t y, const Color &color) { setPixel(y * width + x, color); }

void Bitmap::setPixel(size_t i, const Color &color) { pixels[i] = static_cast<Pixel>(color * 255.0f); }

bool Bitmap::load(const std::string &imgPath)
{
    // TODO bitmap loading
    return false;
}

bool Bitmap::save(const std::string &outPath) const
{
    return stbi_write_png(outPath.c_str(), width, height, 3, pixels.data(), width * 3) > 0;
}

} // namespace holt
