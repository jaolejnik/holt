#pragma once

#include "rect.h"

#include <mutex>
#include <optional>
#include <queue>

namespace holt
{

class TileQueue
{
  private:
    std::queue<Rect> mTiles;
    std::mutex mLock;

  public:
    void init(const glm::ivec2 &frameResolution, const glm::ivec2 &tileResolution);
    std::optional<Rect> pop();
};

} // namespace holt
