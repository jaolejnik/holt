#include "camera.h"
#include "interval.h"
#include "materials/material.h"
#include "utils.h"

#include <glm/glm.hpp>
#include <iostream>

namespace holt
{

void Camera::update()
{
    mForward = glm::normalize(mLookAt - mPosition);
    mRight = glm::normalize(glm::cross(mForward, glm::vec3(0.0f, 1.0f, 0.0f)));
    mUp = glm::normalize(glm::cross(mRight, mForward));

    float planeHeight = mFocusDistance * glm::tan(glm::radians(mFOVDegrees) / 2.0f) * 2.0f;
    float planeWidth = planeHeight * mFrame.aspectRatio();
    mPlaneParams = glm::vec3(planeWidth, planeHeight, mFocusDistance);
}

Ray Camera::getRay(const glm::vec2 &point) const
{
    auto defocusJitter = randomVec2InUnitCircle() * mDefocusStrength / mFrame.widthF();
    auto pointLocal = glm::vec3(point, 1.0f) * mPlaneParams;
    auto rayOrigin = mPosition + defocusJitter.x * mRight + defocusJitter.y * mUp;
    auto rayTarget = mPosition + pointLocal.x * mRight + pointLocal.y * mUp + pointLocal.z * mForward;
    auto rayDirection = rayTarget - rayOrigin;

    return Ray(rayOrigin, rayDirection);
}

const Color Camera::traceRay(const holt::Ray &ray, const holt::Hittable &world, int depth) const
{
    if (depth <= 0) return Color(0.0f);

    HitRecord hitRecord;
    if (!world.hit(ray, holt::Interval(0.001f, holt::infinity), hitRecord)) return mBackground;

    Ray scatteredRay;
    Color attenuation;
    Color emmittedLight = hitRecord.material->emit();
    if (!hitRecord.material->scatter(ray, hitRecord, attenuation, scatteredRay)) return emmittedLight;

    return emmittedLight + attenuation * traceRay(scatteredRay, world, depth - 1);
}

void Camera::render(const Hittable &world)
{
    for (int y = mFrame.height() - 1; y >= 0; --y)
    {
        std::cout << "\rScanlines remaining: " << y << ' ' << std::flush;
        for (int x = 0; x < mFrame.width(); ++x)
        {
            Color color(0.0f);
            auto pixelCoords = glm::vec2(x, y);

            for (float i = 0.0f; i < mSamplingRate; ++i)
            {
                for (float j = 0.0f; j < mSamplingRate; ++j)
                {
                    auto dv = (glm::vec2(i, j) + randomVec2()) / static_cast<float>(mSamplingRate);

                    // auto p = (2.0f * (pixelCoords + dv) - mFrame.resolution()) / mFrame.heightF();
                    auto p = (pixelCoords + dv) / mFrame.resolution() - 0.5f;
                    Ray ray = getRay(p);
                    color += traceRay(ray, world, mMaxDepth);
                }
            }

            color *= 1.0f / (mSamplingRate * mSamplingRate);
            color = glm::clamp(color, 0.0f, 1.0f);
            color = glm::sqrt(color);

            mFrame.setPixel(x, mFrame.height() - 1 - y, color);
        }
    }
    std::cout << "\nDone!\n";
}

} // namespace holt
