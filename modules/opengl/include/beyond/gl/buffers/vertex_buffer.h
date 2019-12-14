#ifndef BEYONDENGINE_VERTEX_BUFFER_H
#define BEYONDENGINE_VERTEX_BUFFER_H

#include <beyond/gl/buffers/buffers.h>

namespace beyond {

    struct VertexLayoutElement : LayoutElement {
    private:
        GLenum type;
        bool normalized;
    public:
        GLenum getType() const;

        bool isNormalized() const;
    };

    typedef Layout<VertexLayoutElement> VertexLayout;

    struct VertexBuffer : BindableMixin<GL_ARRAY_BUFFER> {
    private:
        VertexLayout layout;
    public:
        VertexBuffer(
                VertexLayout layout,
                const std::vector<uint8_t> &data
        );
    };


}
#endif
