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
    forward = glm::normalize(lookAt - position);
    right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
    up = glm::normalize(glm::cross(right, forward));

    float planeHeight = focusDistance * glm::tan(glm::radians(FOVDegrees) / 2.0f) * 2.0f;
    float planeWidth = planeHeight * frame.aspectRatio();
    clipPlaneParams = glm::vec3(planeWidth, planeHeight, focusDistance);
}

Ray Camera::getRay(const glm::vec2 &point) const
{
    auto defocusJitter = randomVec2InUnitCircle() * defocusStrength / frame.widthF();
    auto pointLocal = glm::vec3(point, 1.0f) * clipPlaneParams;
    auto rayOrigin = position + defocusJitter.x * right + defocusJitter.y * up;
    auto rayTarget = position + pointLocal.x * right + pointLocal.y * up + pointLocal.z * forward;
    auto rayDirection = rayTarget - rayOrigin;

    return Ray(rayOrigin, rayDirection);
}

const Color Camera::traceRay(const holt::Ray &ray, const holt::Hittable &world, int depth) const
{
    if (depth <= 0) return Color(0.0f);

    HitRecord hitRecord;
    if (!world.hit(ray, holt::Interval(0.001f, holt::infinity), hitRecord)) return background;

    Ray scatteredRay;
    Color attenuation;
    Color emmittedLight = hitRecord.material->emit();
    if (!hitRecord.material->scatter(ray, hitRecord, attenuation, scatteredRay)) return emmittedLight;

    return emmittedLight + attenuation * traceRay(scatteredRay, world, depth - 1);
}

void Camera::render(const Hittable &world)
{
    for (int y = frame.height - 1; y >= 0; --y)
    {
        std::cout << "\rScanlines remaining: " << y << ' ' << std::flush;
        for (int x = 0; x < frame.width; ++x)
        {
            Color color(0.0f);
            auto pixelCoords = glm::vec2(x, y);

            for (float i = 0.0f; i < samplingRate; ++i)
            {
                for (float j = 0.0f; j < samplingRate; ++j)
                {
                    auto dv = (glm::vec2(i, j) + randomVec2()) / static_cast<float>(samplingRate);

                    // auto p = (2.0f * (pixelCoords + dv) - frame.resolution()) / frame.heightF();
                    auto p = (pixelCoords + dv) / frame.resolution() - 0.5f;
                    Ray ray = getRay(p);
                    color += traceRay(ray, world, maxDepth);
                }
            }

            color *= 1.0f / (samplingRate * samplingRate);
            color = glm::clamp(color, 0.0f, 1.0f);
            color = glm::sqrt(color);

            frame.setPixel(x, frame.height - 1 - y, color);
        }
    }
    std::cout << "\nDone!\n";
}

} // namespace holt
