#include <beyond/gl/buffers/vertex_buffer.h>

namespace beyond {

    VertexBuffer::VertexBuffer(
            VertexLayout layout,
            void * data,
            size_t size
    ) : layout(std::move(layout)) {
        glNamedBufferData(
                id,
                size,
                data,
                GL_STATIC_DRAW
        );
    }

    const VertexLayout &VertexBuffer::getLayout() const {
        return layout;
    }

    GLenum VertexLayoutElement::getType() const {
        return type;
    }

    bool VertexLayoutElement::isNormalized() const {
        return normalized;
    }

    VertexLayoutElement::VertexLayoutElement(uint8_t elementLength, uint8_t elementCount, GLenum type, bool normalized)
            : LayoutElement(elementLength, elementCount), type(type), normalized(normalized) {}

    void VertexLayout::onAdded(const VertexLayoutElement &element) {
        stride += element.getElementSize();
    }

    uint32_t VertexLayout::getStride() const {
        return stride;
    }
}