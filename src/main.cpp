#include "core/bitmap.h"
#include "core/camera.h"
#include "core/ray.h"

#include <glm/glm.hpp>
#include <iostream>

bool hitSphere(const glm::vec3 &center, float radius, const holt::Ray &ray)
{
    auto oc = ray.origin() - center;
    auto a = glm::dot(ray.direction(), ray.direction());
    auto b = 2.0 * glm::dot(oc, ray.direction());
    auto c = glm::dot(oc, oc) - radius * radius;

    return (b * b - 4.0f * a * c) > 0.0f;
}

holt::Color rayColor(const holt::Ray &ray)
{
    if (hitSphere(glm::vec3(0.0f, 0.0f, 1.0f), 0.5f, ray))
        return holt::Colors::RED;
    auto t = 0.5f * (ray.direction().y + 1.0f);
    auto cf = (1.0f - t) * holt::Color(1.0f) + t * holt::Color(0.3f, 0.5f, 1.0f);

    return glm::sqrt(cf); // gamma correction here?
}

int main()
{
    const glm::vec3 origin = glm::vec3(0.0f);
    const glm::vec2 res{1024, 768};

    holt::Camera camera(glm::vec3(0.0f, 0.0f, -1.0f), origin);
    holt::Bitmap frame(res.x, res.y);

    for (int y = res.y - 1; y >= 0; y--)
    {
        std::cout << "\rScanlines remaining: " << y << ' ' << std::flush;
        for (int x = 0; x < res.x; x++)
        {
            auto p = (2.0f * glm::vec2(x, y) - res) / res.y;
            holt::Ray ray(camera.position(), camera.rayDirection(p));
            auto color = rayColor(ray);

            frame.setPixel(x, y, color);
        }
    }
    std::cout << "\nDone!\n";

    frame.save("out.png");

    return 0;
}
