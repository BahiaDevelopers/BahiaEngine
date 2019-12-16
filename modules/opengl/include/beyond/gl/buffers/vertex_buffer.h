#ifndef BEYONDENGINE_VERTEX_BUFFER_H
#define BEYONDENGINE_VERTEX_BUFFER_H

#include <beyond/gl/buffers/buffers.h>

namespace beyond {

    struct VertexLayoutElement : LayoutElement {
    private:
        GLenum type;
        bool normalized;
    public:
        VertexLayoutElement(uint8_t elementLength, uint8_t elementCount, GLenum type, bool normalized);

        GLenum getType() const;

        bool isNormalized() const;
    };

    class VertexLayout : public Layout<VertexLayoutElement> {
    private:
        uint32_t stride = 0;
    protected:
        void onAdded(const VertexLayoutElement &element) override;

    public:
        uint32_t getStride() const;
    };

    struct VertexBuffer : public BindableMixin<GL_ARRAY_BUFFER> {
    private:
        VertexLayout layout;
    public:
        const VertexLayout &getLayout() const;

        VertexBuffer(
                VertexLayout layout,
                void *data,
                size_t size
        );
    };


}
#endif
