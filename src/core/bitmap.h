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
        std::vector<Pixel> mPixels;
        size_t mWidth;
        size_t mHeight;

    public:
        Bitmap(glm::vec2 resolution, const Color &color = Colors::BLACK);

        void clear();
        void fill(const Color &color);
        void setPixel(size_t x, size_t y, const Color &color);
        void setPixel(size_t i, const Color &color);
        bool load(const std::string &imgPath);
        bool save(const std::string &outPath) const;

        const size_t width() const { return mWidth; }
        const size_t height() const { return mHeight; }
        const float widthF() const { return static_cast<float>(mWidth); }
        const float heightF() const { return static_cast<float>(mHeight); }
        const float aspectRatio() const { return static_cast<float>(mWidth) / static_cast<float>(mHeight); }
        const glm::vec2 resolution() const { return {mWidth, mHeight}; }
    };
} // namespace holt
