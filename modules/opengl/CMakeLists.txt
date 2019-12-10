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

target_link_libraries(
        opengl application entities glfw glew_s
)