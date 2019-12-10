set(
        OPENGL_ALL
        include/beyond/gl/opengl.h
        include/beyond/gl/components.h
        src/beyond/gl/opengl.cpp
)
beyond_module(
        opengl
        "${OPENGL_ALL}"
)
target_include_directories(
        opengl
        PUBLIC
        ${GLFW_INCLUDE_DIRS}
)
target_link_libraries(opengl ${GLFW_LIBRARIES})

target_link_libraries(
        opengl application entities
)