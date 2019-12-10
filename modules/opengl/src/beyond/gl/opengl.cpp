#include <beyond/gl/opengl.h>
#include <stdexcept>
#include <iostream>

namespace beyond {
    void OpenGL::apply(Application &target) {

        target.getEarlyStep() += [&]() {
            if (glfwWindowShouldClose(OpenGL::window)) {
                target.setExecuting(false);
            }
        };
    }

    OpenGL::OpenGL() : window(nullptr) {
        if (glfwInit() != GLFW_TRUE) {
            throw std::runtime_error("Unable to initialize GLFW");
        }
        std::cout << "Initialized GLFW " << glfwGetVersionString() << std::endl;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(600, 800, "OpenGL", nullptr, nullptr);
        glfwMakeContextCurrent(window);
        int glewS;

        if ((glewS = glewInit()) != GLEW_OK) {
            std::string msg = "Unable to initialize GLEW (";
            msg += std::to_string(glewS);
            msg += ") ";
            msg += reinterpret_cast<const char *>(glewGetErrorString(glewS));
            throw std::runtime_error(msg);
        }
        std::cout << "Initialized GLEW " << glewGetString(GLEW_VERSION) << std::endl;
        glfwShowWindow(window);
    }

    GLFWwindow *OpenGL::getWindow() const {
        return window;
    }
}