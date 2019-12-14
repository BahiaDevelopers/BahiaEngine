#ifndef BEYONDENGINE_INDEX_BUFFER_H
#define BEYONDENGINE_INDEX_BUFFER_H

#include <beyond/gl/buffers/buffers.h>
#include <vector>

namespace beyond {

    struct IndexBuffer : BindableMixin<GL_INDEX_ARRAY> {
    private:
    public:
        explicit IndexBuffer(
                std::vector<uint16_t> buf
        );
    };
}
#endif //BEYONDENGINE_INDEX_BUFFER_H
