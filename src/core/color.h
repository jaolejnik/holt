#pragma once

#include <cstdint>
#include <glm/vec3.hpp>

namespace holt
{
    typedef glm::u8vec3 Color;

    namespace Colors
    {
        constexpr Color BLACK = Color(0u);
        constexpr Color WHITE = Color(255u);

        constexpr Color RED = Color(255u, 0u, 0u);
        constexpr Color BLUE = Color(0u, 255u, 0u);
        constexpr Color GREEN = Color(0u, 0u, 255u);
    };
} // namespace holt