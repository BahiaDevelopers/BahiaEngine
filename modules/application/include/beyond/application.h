#ifndef BEYONDENGINE_APPLICATION_H
#define BEYONDENGINE_APPLICATION_H

#include <beyond/extension.h>

namespace beyond {
    class Application : public ExtensibleMixin<Application> {
    public:
        Application() = default;

        ~Application() = default;
    };
}
#endif
