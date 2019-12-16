#include <beyond/application.h>
#include <beyond/gl/opengl.h>
#include <beyond/entities/scene.h>
#include <beyond/entities/entity.h>
#include <beyond/gl/traits/camera.h>
#include <beyond/gl/traits/drawable.h>

int main() {
    beyond::Application app;
    auto gl = new beyond::OpenGL();
    app.apply(gl);
    beyond::Scene *scene = app.applyWith(new beyond::Scene());
    auto *cameraEntity = new beyond::Entity(scene);
    cameraEntity->apply(new beyond::Camera());
    auto quad = beyond::Meshes::getQuad();
    auto plane = new beyond::Entity(scene);
    plane->apply(new beyond::Drawable(quad));
    app.execute();
}