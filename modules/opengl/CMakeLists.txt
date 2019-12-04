beyond_module(
        opengl
        include/beyond/gl/opengl.h
        include/beyond/gl/components.h
        src/beyond/gl/opengl.cpp
)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
target_include_directories(
        opengl
        PUBLIC
        ${GLFW_INCLUDE_DIRS}
)
target_link_libraries(opengl ${GLFW_LIBRARIES})

target_link_libraries(
        opengl application entities
)