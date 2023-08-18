#pragma once

#include "color.h"

#include <glm/vec2.hpp>
#include <vector>
#include <string>

namespace holt
{
    class Bitmap
    {
    private:
        std::vector<Pixel> m_pixels;
        size_t m_width;
        size_t m_height;

    public:
        Bitmap(glm::vec2 resolution, const Color &color = Colors::BLACK);

        void clear();
        void fill(const Color &color);
        void setPixel(size_t x, size_t y, const Color &color);
        void setPixel(size_t i, const Color &color);
        bool load(const std::string &imgPath);
        bool save(const std::string &outPath) const;

        const size_t width() const { return m_width; }
        const size_t height() const { return m_height; }
        const glm::vec2 resolution() const { return {m_width, m_height}; }
    };
} // namespace holt
