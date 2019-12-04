#ifndef BEYONDENGINE_EXTENSION_H
#define BEYONDENGINE_EXTENSION_H

#include <vector>

namespace beyond {


    template<typename T>
    class Extension {
    public:
        virtual void apply(T &target) = 0;
    };

    template<typename T>
    class ExtensibleMixin {
    private:
        std::vector<Extension<T> *> extensions;
    public:
        void apply(Extension<T> *extension) {
            extension->apply(*static_cast<T *>(this));
            extensions.push_back(extension);
        }
/*

        template<typename E>
        E *find_extension() {
            for (Extension<T> *ext : extensions) {
                E candidate = dynamic_cast<E *>(ext);
                if (candidate != nullptr) {
                    return candidate;
                }
            }
            return nullptr;
        }
*/

    };
}
#endif
