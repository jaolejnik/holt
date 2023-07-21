#pragma once

#include "color.h"

#include <vector>
#include <string>

namespace holt
{
    class Bitmap
    {
    private:
        std::vector<Color> m_pixels;
        size_t m_width;
        size_t m_height;

    public:
        Bitmap(int width, int height, const Color &color = Colors::BLACK);

        void clear();
        void fill(const Color &color);
        void setPixel(size_t x, size_t y, const Color &color);
        void setPixel(size_t i, const Color &color);
        bool load(const std::string &imgPath);
        bool save(const std::string &outPath) const;
    };
} // namespace holt