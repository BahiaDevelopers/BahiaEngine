#ifndef BEYONDENGINE_ARRAY_BUFFER_H
#define BEYONDENGINE_ARRAY_BUFFER_H

#include <beyond/gl/buffers/buffers.h>

namespace beyond {
    class ArrayBuffer {
    private:
        uint32_t id;
    public:
        ArrayBuffer(
                const IndexBuffer &indexBuffer,
                const VertexBuffer &vertexBuffer
        ) : id(-1) {
            glGenVertexArrays(1, &id);
            bind();
            vertexBuffer.bind();
            indexBuffer.bind();
            uint32_t i = 0;
            const auto &layout = vertexBuffer.getLayout();
            uint32_t stride = layout.getStride();
            for (const VertexLayoutElement &element : layout.getElements()) {

                glEnableVertexArrayAttrib(id, i);
                glVertexAttribPointer(
                        i,
                        element.getElementSize(),
                        element.getType(),
                        element.isNormalized(),
                        stride,
                        nullptr
                );
                i++;
            }
            //Save state
            unbind();
        }

        void bind() const {
            glBindVertexArray(id);
        }

        void unbind() {
            glBindVertexArray(0);
        }
    };
}
#endif
