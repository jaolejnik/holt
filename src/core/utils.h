#pragma once

#include <random>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/norm.hpp>

namespace holt
{

    float random()
    {
        static std::uniform_real_distribution<float> distribution(0.0, 1.0);
        static std::mt19937 generator;
        return distribution(generator);
    }

    float randomRange(float min, float max) { return min + ((max - min) * random()); }

    glm::vec2 randomVec2() { return {random(), random()}; }

    glm::vec2 randomVec2Range(float min, float max)
    {
        return {
            randomRange(min, max),
            randomRange(min, max)};
    }

    glm::vec3 randomVec3() { return {random(), random(), random()}; }

    glm::vec3 randomVec3Range(float min, float max)
    {
        return {
            randomRange(min, max),
            randomRange(min, max),
            randomRange(min, max)};
    }

    glm::vec3 randomVec3InUnitSphere()
    {
        while (true)
        {
            auto p = randomVec3Range(-1.0f, 1.0f);
            if (glm::length2(p) >= 1.0f)
                continue;
            return p;
        }
    }

    glm::vec3 randomUnitVec3() { return glm::normalize(randomVec3InUnitSphere()); }

    glm::vec3 randomVec3InHemisphere(const glm::vec3 &normal)
    {
        auto v = randomVec3InUnitSphere();
        return glm::dot(v, normal) > 0.0f ? v : -v;
    }

}
