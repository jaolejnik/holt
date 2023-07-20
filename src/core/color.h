#pragma once

#include <cstdint>

namespace holt
{
    struct Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

    namespace Colors
    {
        constexpr Color BLACK{0u, 0u, 0u, 255u};
        constexpr Color WHITE{255u, 255u, 255u, 255u};

        constexpr Color RED{255u, 0u, 0u, 255u};
        constexpr Color BLUE{0u, 255u, 0u, 255u};
        constexpr Color GREEN{0u, 0u, 255u, 255u};
    };
} // namespace holt