#pragma once

#include "hittable.h"
#include "interval.h"

#include <memory>
#include <vector>

namespace holt
{

class HittableList : public Hittable
{
  private:
    std::vector<std::shared_ptr<Hittable>> mObjects;

  public:
    HittableList() {}
    HittableList(std::shared_ptr<Hittable> object) { add(object); }

    void add(std::shared_ptr<Hittable> object) { mObjects.push_back(object); }
    void clear() { mObjects.clear(); }

    bool hit(const Ray &ray, Interval rayT, HitRecord &hitRecord) const override
    {
        HitRecord tmpHitRecord;
        bool anyHit   = false;
        auto closestT = rayT.max;

        for (const auto &object : mObjects)
        {
            if (object->hit(ray, Interval(rayT.min, closestT), tmpHitRecord))
            {
                anyHit    = true;
                closestT  = tmpHitRecord.t;
                hitRecord = tmpHitRecord;
            }
        }

        return anyHit;
    }
};

} // namespace holt
