#include "renderer.h"
#include "hittable.h"
#include "interval.h"
#include "materials/material.h"
#include "utils.h"

#include <chrono>
#include <iostream>
#include <thread>

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;

namespace holt
{

Renderer::Renderer(const glm::vec2 &resolution) : frame(resolution), availableCores(std::thread::hardware_concurrency())
{
    tiles.init(resolution, tileResolution);
}

const Color Renderer::traceRay(const holt::Ray &ray, const holt::Hittable &world, int depth) const
{
    if (depth <= 0)
        return Color(0.0f);

    HitRecord hitRecord;
    if (!world.hit(ray, holt::Interval(0.001f, holt::infinity), hitRecord))
        return background;

    Ray scatteredRay;
    Color attenuation;
    Color emmittedLight = hitRecord.material->emit();
    if (!hitRecord.material->scatter(ray, hitRecord, attenuation, scatteredRay))
        return emmittedLight;

    return emmittedLight + attenuation * traceRay(scatteredRay, world, depth - 1);
}

void Renderer::render(const Camera &camera, const Hittable &world)
{
    auto start = high_resolution_clock::now();

    auto renderTile = [this](const Camera &camera, const Hittable &world) {
        while (!tiles.isEmpty())
        {
            Rect tile = tiles.pop();
            int maxX  = tile.x + tile.width;
            int maxY  = tile.y + tile.height;

            for (int y = tile.y; y < maxY; ++y)
            {
                for (int x = tile.x; x < maxX; ++x)
                {
                    Color color(0.0f);
                    auto pixelCoords = glm::vec2(x, y);

                    for (float i = 0.0f; i < samplingRate; ++i)
                    {
                        for (float j = 0.0f; j < samplingRate; ++j)
                        {
                            auto dv = (glm::vec2(i, j) + randomVec2()) / static_cast<float>(samplingRate);

                            auto p  = (pixelCoords + dv) / frame.resolution() - 0.5f;
                            Ray ray = getRay(camera, p);
                            color += traceRay(ray, world, maxDepth);
                        }
                    }

                    color *= 1.0f / (samplingRate * samplingRate);
                    color = glm::clamp(color, 0.0f, 1.0f);
                    color = glm::sqrt(color);

                    frame.setPixel(x, frame.height - 1 - y, color);
                }
            }
        }
    };

    std::vector<std::thread> workers;

    for (int i = 0; i < availableCores; ++i)
        workers.emplace_back(renderTile, std::cref(camera), std::cref(world));

    for (auto &worker : workers)
        worker.join();

    auto stop        = high_resolution_clock::now();
    auto elapsedTime = duration_cast<milliseconds>(stop - start).count();
    std::cout << "\nDone! Finished in " << formatTime(elapsedTime) << "\n";
}

Ray Renderer::getRay(const Camera &camera, const glm::vec2 &point) const
{
    auto defocusJitter = randomVec2InUnitCircle() * camera.defocusStrength / frame.widthF();
    auto pointLocal    = glm::vec3(point, 1.0f) * camera.getClipPlaneParams();
    auto rayOrigin     = camera.position + defocusJitter.x * camera.getRight() + defocusJitter.y * camera.getUp();
    auto rayTarget     = camera.position + pointLocal.x * camera.getRight() + pointLocal.y * camera.getUp() +
                     pointLocal.z * camera.getForward();
    auto rayDirection = rayTarget - rayOrigin;

    return Ray(rayOrigin, rayDirection);
}

} // namespace holt
