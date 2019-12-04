#include <beyond/application.h>
#include <beyond/gl/opengl.h>

int main() {
    beyond::Application app;
    app.apply(new beyond::OpenGL());
}