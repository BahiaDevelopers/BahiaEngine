#include <beyond/application.h>

namespace beyond {
    Event<> &Application::getEarlyStep() {
        return earlyStep;
    }

    Event<> &Application::getStep() {
        return step;
    }

    Event<> &Application::getLateStep() {
        return lateStep;
    }

    bool Application::isExecuting() const {
        return executing;
    }

    void Application::setExecuting(bool executing) {
        Application::executing = executing;
    }

    void Application::execute() {
        executing = true;
        while (executing) {
            earlyStep();
            step();
            lateStep();
        }
    }
}