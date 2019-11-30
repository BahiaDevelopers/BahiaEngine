#ifndef BEYONDENGINE_EXTENSION_H
#define BEYONDENGINE_EXTENSION_H

#include <vector>

namespace beyond {


    template<typename T>
    class Extension {
        virtual void apply(T &target) = 0;
    };

    template<typename T>
    class ExtensibleMixin {
    private:
        std::vector <T> extensions;
    public:
        void apply(Extension<T> extension) {
            extension.apply(*this)
        }

    };
}
#endif
