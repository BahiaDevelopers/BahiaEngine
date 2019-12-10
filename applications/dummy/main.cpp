#include <beyond/application.h>
#include <beyond/gl/opengl.h>

int main() {
    beyond::Application app;
    auto gl = new beyond::OpenGL();
    app.apply(gl);
    while (!glfwWindowShouldClose(gl->getWindow())) {
        glfwPollEvents();
    }
}