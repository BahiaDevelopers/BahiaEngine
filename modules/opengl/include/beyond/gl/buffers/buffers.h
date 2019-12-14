

#ifndef BEYONDENGINE_BUFFERS_H
#define BEYONDENGINE_BUFFERS_H

#include <cstdint>
#include <utility>
#include <GL/glew.h>
#include <beyond/utilities/layout.h>

namespace beyond {
    template<GLenum TARGET>
    struct BindableMixin {
    protected:
        uint32_t id;
    public:
        BindableMixin() : id(-1) {
            glGenBuffers(1, &id);
        }

    public:
        void bind() {
            glBindBuffer(TARGET, id);
        }

        void unbind() {
            glBindBuffer(TARGET, 0);
        }
    };

}
#endif
