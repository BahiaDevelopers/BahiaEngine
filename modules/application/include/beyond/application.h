#ifndef BEYONDENGINE_APPLICATION_H
#define BEYONDENGINE_APPLICATION_H

#include <beyond/extension.h>
#include <beyond/event.h>

namespace beyond {
    class Application : public ExtensibleMixin<Application> {
    private:
        bool executing;
        Event<> earlyStep, step, lateStep;
    public:
        Application() = default;

        ~Application() = default;

        Event<> &getEarlyStep();

        Event<> &getStep();

        Event<> &getLateStep();

        bool isExecuting() const;

        void setExecuting(bool executing);
        void execute();
    };
}
#endif
