#ifndef BEYONDENGINE_MESH_H
#define BEYONDENGINE_MESH_H

#include <beyond/gl/buffers/index_buffer.h>
#include <beyond/gl/buffers/vertex_buffer.h>
#include <beyond/gl/buffers/array_buffer.h>

namespace beyond {
    class Mesh {
    private:
        VertexBuffer vertex;
        IndexBuffer index;
        ArrayBuffer array;
    public:
        static Mesh quad() {

        }

        Mesh(
                VertexBuffer vertex,
                IndexBuffer index,
                ArrayBuffer array
        );

        const VertexBuffer &getVertex() const;

        const IndexBuffer &getIndex() const;

        const ArrayBuffer &getArray() const;
    };

    class Meshes {
    private:
        static Mesh *quad;

        static Mesh *createQuad();

    public:
        static Mesh *getQuad();
    };
}
#endif
