add_library(holt_core)

target_sources(
    holt_core
    PUBLIC 
        # HEADERS
        [[color.h]]
        [[bitmap.h]]
        [[camera.h]]
        [[ray.h]]
    PRIVATE
        # SOURCES
        [[bitmap.cpp]]
        [[camera.cpp]]
)

target_include_directories(
    holt_core
	PUBLIC
	    "${CMAKE_SOURCE_DIR}/src"
		"${CMAKE_BINARY_DIR}"
)

target_include_directories(
    holt_core
    PUBLIC 
        ${Stb_INCLUDE_DIR}
)

target_link_libraries(
    holt_core
    PUBLIC 
        glm::glm
)