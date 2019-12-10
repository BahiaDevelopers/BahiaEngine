#ifndef BEYONDENGINE_OPENGL_H
#define BEYONDENGINE_OPENGL_H

#include <beyond/application.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace beyond {
    class OpenGL : public Extension<Application> {
    private:
        GLFWwindow *window;

    public:
        OpenGL(

        );

        void apply(Application &target) override;

        GLFWwindow *getWindow() const;
    };


}
#endif
