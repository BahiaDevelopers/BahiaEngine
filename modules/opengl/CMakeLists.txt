set(
        OPENGL_ALL
        include/beyond/gl/mesh.h
        include/beyond/gl/material.h
        include/beyond/gl/opengl.h
        include/beyond/gl/traits/drawable.h
        include/beyond/gl/buffers/buffers.h
        include/beyond/gl/traits/camera.h
        include/beyond/gl/buffers/vertex_buffer.h
        include/beyond/gl/buffers/index_buffer.h
        src/beyond/gl/opengl.cpp
)
beyond_module(
        opengl
        "${OPENGL_ALL}"
)

target_link_libraries(
        opengl application entities glfw glew_s
)