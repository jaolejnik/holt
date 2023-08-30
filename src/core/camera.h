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
        int mMaxDepth = 10;

        float mFOVDegrees = 90.0f;
        float mFocusDistance = 1.0f;
        float mDefocusStrength = 0.0f;

        glm::vec3 mLookAt = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 mPosition = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 mForward;
        glm::vec3 mRight;
        glm::vec3 mUp;
        glm::vec3 mPlaneParams;

        Color mBackground = Color(0.0f);
        Bitmap mFrame;

    public:
        Camera(const glm::vec2 &resolution) : mFrame(resolution) {}

        void update();
        Ray getRay(const glm::vec2 &point) const;
        const Color traceRay(const Ray &ray, const Hittable &world, int depth) const;
        void render(const Hittable &world);
        void saveFrame(const std::string &outPath) const { mFrame.save(outPath); }

        void setSamplingRate(int samplingRate) { mSamplingRate = samplingRate; }
        void setMaxDepth(int maxDepth) { mMaxDepth = maxDepth; }
        void setFOV(float FOVDegrees) { mFOVDegrees = FOVDegrees; }
        void setFocusDistance(float focusDistance) { mFocusDistance = focusDistance; }
        void setDefocusStrength(float defocusStrength) { mDefocusStrength = defocusStrength; }
        void setLookAt(glm::vec3 lookAt) { mLookAt = lookAt; }
        void setPosition(glm::vec3 position) { mPosition = position; }

        // TODO getters?
    };
} // namespace holt
