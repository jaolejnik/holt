#pragma once

#include "bitmap.h"
#include "color.h"
#include "ray.h"
#include "hittable.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace holt
{
    class Camera
    {
    private:
        int mSamplingRate = 3;
        int mMaxDepth = 50;
        glm::vec3 mPosition;
        glm::vec3 mForward;
        glm::vec3 mRight;
        glm::vec3 mUp;
        Bitmap mFrame;

    public:
        Camera(glm::vec3 position, const glm::vec3 &origin, const glm::vec2 &resolution, int samplingRate);

        const glm::vec3 rayDirection(const glm::vec2 &point) const;
        const Color traceRay(const Ray &ray, const Hittable &world, int depth) const;
        void render(const Hittable &world);

        void saveFrame(const std::string &outPath) const { mFrame.save(outPath); }
        const glm::vec3 position() const { return mPosition; }
    };
} // namespace holt
