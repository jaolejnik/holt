#include "core/bitmap.h"
#include "core/camera.h"

#include <glm/glm.hpp>
#include <iostream>

int main()
{
    const glm::vec3 origin = glm::vec3(0.0f);
    const int res_width = 1280;
    const int res_height = 720;

    holt::Camera camera(glm::vec3(0.0f, 1.0f, -1.0f), origin);
    holt::Bitmap frame(res_width, res_height);

    frame.save("out.png");

    return 0;
}