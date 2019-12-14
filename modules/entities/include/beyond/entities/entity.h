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
        explicit Entity(Scene *scene) : scene(scene), earlyStep(), step(), lateStep() {

        }

        Event<> &getEarlyStep() {
            return earlyStep;
        }

        Event<> &getStep() {
            return step;
        }

        Event<> &getLateStep() {
            return lateStep;
        }

        Scene *getScene() {
            return scene;
        }
    };

    typedef Extension<Entity> Trait;
}
#endif
