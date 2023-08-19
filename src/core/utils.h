#pragma once

#include <random>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace holt
{

    float random()
    {
        static std::uniform_real_distribution<float> distribution(0.0, 1.0);
        static std::mt19937 generator;
        return distribution(generator);
    }

    glm::vec2 randomVec2() { return {random(), random()}; }
    glm::vec3 randomVec3() { return {random(), random(), random()}; }
}
