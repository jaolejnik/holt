#pragma once

#include <cstdint>
#include <glm/vec3.hpp>

namespace holt
{
    using Pixel = glm::u8vec3;
    using Color = glm::vec3;

    namespace Colors
    {
        constexpr Color BLACK = Color(0.0f);
        constexpr Color WHITE = Color(1.0f);

        constexpr Color RED = Color(1.0f, 0.0f, 0u);
        constexpr Color BLUE = Color(0.0f, 1.0f, 0u);
        constexpr Color GREEN = Color(0.0f, 0u, 1.0f);
    };
} // namespace holt
