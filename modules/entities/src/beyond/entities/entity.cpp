#include <beyond/entities/entity.h>
namespace beyond {

    Entity::Entity(Scene *scene) : scene(scene), earlyStep(), step(), lateStep() {
        scene->addEntity(this);
    }

    Event<> &Entity::getEarlyStep() {
        return earlyStep;
    }

    Event<> &Entity::getStep() {
        return step;
    }

    Event<> &Entity::getLateStep() {
        return lateStep;
    }

    Scene *Entity::getScene() {
        return scene;
    }
}