#pragma once

#include <limits>

namespace holt
{

constexpr float infinity = std::numeric_limits<float>::infinity();

class Interval
{
  public:
    static const Interval empty;
    static const Interval universe;

    float min;
    float max;

    Interval() : min(infinity), max(-infinity) {}
    Interval(float min, float max) : min{min}, max{max} {}

    bool contains(float x) const { return min <= x && x <= max; }
    bool surrounds(float x) const { return min < x && x < max; }
};

static const Interval empty(infinity, -infinity);
static const Interval universe(-infinity, infinity);

} // namespace holt
