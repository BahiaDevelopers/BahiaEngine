#include <beyond/application.h>
#include <beyond/gl/opengl.h>

int main() {
    beyond::Application application;
    application.apply(new beyond::OpenGL());
}