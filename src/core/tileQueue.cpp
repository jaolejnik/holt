#include "tileQueue.h"

namespace holt
{

void TileQueue::init(const glm::ivec2 &frameResolution, const glm::ivec2 &tileResolution)
{
    for (int y = frameResolution.y - tileResolution.y; y >= 0; y -= tileResolution.y)
        for (int x = 0; x < frameResolution.x; x += tileResolution.x)
            mTiles.emplace(glm::ivec2(x, y), tileResolution);
}

std::optional<Rect> TileQueue::pop()
{
    std::lock_guard<std::mutex> guard(mLock);

    if (mTiles.empty())
        return std::nullopt;

    auto tile = mTiles.front();
    mTiles.pop();

    return tile;
}

} // namespace holt
