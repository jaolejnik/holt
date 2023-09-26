#pragma once

#include "rect.h"

#include <memory>
#include <mutex>
#include <queue>

namespace holt
{

class TileQueue
{
  private:
    std::queue<Rect> tiles;
    std::mutex lock;

  public:
    void init(const glm::ivec2 &frameResolution, const glm::ivec2 &tileResolution)
    {
        for (int y = frameResolution.y - tileResolution.y; y >= 0; y -= tileResolution.y)
            for (int x = 0; x < frameResolution.x; x += tileResolution.x)
                tiles.emplace(glm::ivec2(x, y), tileResolution);
    }

    Rect pop()
    {
        std::lock_guard<std::mutex> guard(lock);

        auto tile = tiles.front();
        tiles.pop();

        return tile;
    }

    bool isEmpty()
    {
        std::lock_guard<std::mutex> guard(lock);
        return tiles.empty();
    }
};

} // namespace holt
