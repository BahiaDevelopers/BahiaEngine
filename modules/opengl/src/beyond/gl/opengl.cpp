#include <beyond/gl/opengl.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace beyond {
    void OpenGL::apply(Application &target) {

    }

    OpenGL::OpenGL() : window(nullptr) {
        if (glfwInit() != GLFW_TRUE) {
            throw std::runtime_error("Unable to initialize opengl");
        }
    }
}