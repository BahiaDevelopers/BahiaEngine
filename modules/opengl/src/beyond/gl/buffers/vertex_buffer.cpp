#include <beyond/gl/buffers/vertex_buffer.h>

namespace beyond {

    VertexBuffer::VertexBuffer(
            VertexLayout layout,
            const std::vector<uint8_t> &data
    ) : layout(std::move(layout)) {
        glNamedBufferData(
                id,
                data.size(),
                data.data(),
                GL_STATIC_DRAW
        );
    }

    GLenum VertexLayoutElement::getType() const {
        return type;
    }

    bool VertexLayoutElement::isNormalized() const {
        return normalized;
    }
}