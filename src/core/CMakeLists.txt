add_library(holt_core)

target_sources(
    holt_core
    PUBLIC 
        # HEADERS
        [[utils.h]]
        [[color.h]]
        [[bitmap.h]]
        [[camera.h]]
        [[rect.h]]
        [[tileQueue.h]]
        [[renderer.h]]
        [[ray.h]]
        [[hittable.h]]
        [[hittableList.h]]
        [[interval.h]]
        [[sphere.h]]
        [[materials/material.h]]
        [[materials/materials.h]]
        [[materials/diffuse.h]]
        [[materials/metal.h]]
        [[materials/clear.h]]
        [[materials/diffuseLight.h]]
    PRIVATE
        # SOURCES
        [[bitmap.cpp]]
        [[camera.cpp]]
        [[renderer.cpp]]
        [[sphere.cpp]]
        [[utils.cpp]]
        [[materials/diffuse.cpp]]
        [[materials/metal.cpp]]
        [[materials/clear.cpp]]
)

target_include_directories(
    holt_core
	PUBLIC
	    "${CMAKE_SOURCE_DIR}/src"
		"${CMAKE_BINARY_DIR}"
        "${Stb_INCLUDE_DIR}"
)

target_link_libraries(
    holt_core
    PUBLIC 
        glm::glm
)
