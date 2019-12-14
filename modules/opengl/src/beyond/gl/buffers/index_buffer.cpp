#include <beyond/gl/buffers/index_buffer.h>

namespace beyond {
    IndexBuffer::IndexBuffer(std::vector <uint16_t> buf) {
        glNamedBufferData(
                GL_INDEX_ARRAY,
                buf.size(),
                buf.data(),
                GL_STATIC_DRAW
        );
    }

}