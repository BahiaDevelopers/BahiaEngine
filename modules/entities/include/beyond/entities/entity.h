#ifndef BEYONDENGINE_ENTITY_H
#define BEYONDENGINE_ENTITY_H

#include <beyond/extension.h>
#include <beyond/event.h>
#include <beyond/entities/scene.h>

namespace beyond {
    class Entity : public ExtensibleMixin<Entity> {
    private:
        Scene *scene;
        Event<> earlyStep, step, lateStep;
    public:
        explicit Entity(Scene *scene);

        Event<> &getEarlyStep();

        Event<> &getStep();

        Event<> &getLateStep();

        Scene *getScene();
    };

    typedef Extension<Entity> Trait;
}
#endif
