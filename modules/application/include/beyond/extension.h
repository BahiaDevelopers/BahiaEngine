#ifndef BEYONDENGINE_EXTENSION_H
#define BEYONDENGINE_EXTENSION_H

#include <vector>
#include <beyond/event.h>

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
        Event<Extension<T> *> onExtensionApplied;
    public:
        void apply(Extension<T> *extension) {
            extension->apply(*static_cast<T *>(this));
            extensions.push_back(extension);
        }

        Event<Extension<T> *> &getOnExtensionApplied() {
            return onExtensionApplied;
        }

        template<typename E>
        E *findExtension() {
            for (Extension<T> *ext : extensions) {
                E candidate = dynamic_cast<E *>(ext);
                if (candidate != nullptr) {
                    return candidate;
                }
            }
            return nullptr;
        }

        template<typename E, typename ...A>
        void ensureHas(A... args) {
            if (findExtension<E>() == nullptr) {
                apply(new E(std::forward(args...)));
            }
        }

        template<typename E, typename ...A>
        E *findOrAddExtension(A... args) {
            E *ext = findOrAddExtension<E>();
            if (ext == nullptr) {
                ext = new E(std::forward(args...));
                apply(ext);
            }
            return ext;
        }
    };
}
#endif
