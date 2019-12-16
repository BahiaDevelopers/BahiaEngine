#include <beyond/gl/mesh.h>
#include <glm/glm.hpp>
#include <utility>

namespace beyond {

    Mesh::Mesh(
            VertexBuffer vertex,
            IndexBuffer index,
            ArrayBuffer array
    ) : vertex(std::move(vertex)),
        index(std::move(index)),
        array(std::move(array)) {}

    const VertexBuffer &Mesh::getVertex() const {
        return vertex;
    }

    const IndexBuffer &Mesh::getIndex() const {
        return index;
    }

    const ArrayBuffer &Mesh::getArray() const {
        return array;
    }

    Mesh *Meshes::createQuad() {
        std::vector<uint16_t> indices = {
                0, 1, 2, 2, 3, 0
        };
        std::vector<glm::vec3> vertices = {
                glm::vec3(-0.5F, -0.5F, 0),
                glm::vec3(-0.5F, 0.5F, 0),
                glm::vec3(0.5F, 0.5F, 0),
                glm::vec3(0.5F, -0.5F, 0)
        };
        IndexBuffer index(indices);
        auto layout = VertexLayout();
        layout.emplace(
                sizeof(glm::vec3),
                1,
                GL_FLOAT,
                false
        );
        VertexBuffer vertex(
                layout,
                vertices.data(),
                vertices.size() * sizeof(glm::vec3)
        );
        ArrayBuffer array(index, vertex);
        return new Mesh(
                vertex,
                index,
                array
        );
    }

    Mesh *Meshes::getQuad() {
        if (quad == nullptr) {
            return (quad = createQuad());
        }
    }
}