#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <string>

namespace holt
{

float random();

float randomRange(float min, float max);

glm::vec2 randomVec2();

glm::vec2 randomVec2Range(float min, float max);

glm::vec2 randomVec2InUnitCircle();

glm::vec3 randomVec3();

glm::vec3 randomVec3Range(float min, float max);

glm::vec3 randomVec3InUnitSphere();

glm::vec3 randomUnitVec3();

glm::vec3 randomVec3InHemisphere(const glm::vec3 &normal);

bool isAlmostZero(const glm::vec3 &v);

std::tuple<int, int> divide(int dividend, int divisor);

std::string formatTime(long long timeMs);

} // namespace holt
