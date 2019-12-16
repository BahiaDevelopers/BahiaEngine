#ifndef BEYONDENGINE_DRAWABLE_H
#define BEYONDENGINE_DRAWABLE_H

#include <beyond/entities/entity.h>
#include <beyond/gl/mesh.h>

#include <utility>

namespace beyond {
    class Drawable : public Extension<Entity> {
    private:
        Mesh *mesh;
    public:
        Drawable(Mesh *mesh) : mesh(mesh) {}

        void apply(Entity &target) override {

        }

        void draw() {
            mesh->getArray().bind();
            glDrawElements(
                    GL_TRIANGLES,
            )
        }
    };
}
#endif