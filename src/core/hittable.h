#pragma once

#include "interval.h"
#include "ray.h"

#include <glm/glm.hpp>
#include <memory>

namespace holt
{

class Material;

class HitRecord
{
  public:
    glm::vec3 point;
    glm::vec3 normal;
    float t;
    bool frontFace;
    std::shared_ptr<Material> material;

    void setFaceNormal(const Ray &ray, const glm::vec3 &outwardNormal)
    {
        frontFace = glm::dot(ray.direction, outwardNormal) < 0.0f;
        normal    = frontFace ? outwardNormal : -outwardNormal;
    }
};

class Hittable
{
  public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray &ray, Interval rayT, HitRecord &hitRecord) const = 0;
};

} // namespace holt
