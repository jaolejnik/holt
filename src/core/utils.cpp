#include "utils.h"

namespace holt
{
    float random()
    {
        static std::uniform_real_distribution<float> distribution(0.0, 1.0);
        static std::mt19937 generator;
        return distribution(generator);
    }

    float randomRange(float min, float max)
    {
        return min + ((max - min) * random());
    }

    glm::vec2 randomVec2()
    {
        return {random(), random()};
    }

    glm::vec2 randomVec2Range(float min, float max)
    {
        return {
            randomRange(min, max),
            randomRange(min, max)};
    }

    glm::vec2 randomVec2InUnitCircle()
    {
        float theta = 2.0f * glm::pi<float>() * random();
        auto p = glm::vec2(glm::cos(theta), glm::sin(theta));
        return p + glm::sqrt(random());
    }

    glm::vec3 randomVec3()
    {
        return {random(), random(), random()};
    }

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

    glm::vec3 randomUnitVec3()
    {
        return glm::normalize(randomVec3InUnitSphere());
    }

    glm::vec3 randomVec3InHemisphere(const glm::vec3 &normal)
    {
        auto v = randomVec3InUnitSphere();
        return glm::dot(v, normal) > 0.0f ? v : -v;
    }

    bool isAlmostZero(const glm::vec3 &v)
    {
        auto s = 1e-8;
        return glm::all(glm::lessThan(glm::abs(v), glm::vec3(s)));
    }
}
