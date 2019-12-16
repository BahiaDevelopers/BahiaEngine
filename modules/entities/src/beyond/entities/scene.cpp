#include <beyond/entities/scene.h>
#include <beyond/entities/entity.h>

namespace beyond {

    void Scene::addEntity(Entity *entity) {
        entities.push_back(entity);
    }

    void Scene::apply(Application &target) {
        target.getEarlyStep() += [&]() {
            for (Entity *entt : entities) {
                entt->getEarlyStep()();
            }
        };
        target.getStep() += [&]() {
            for (Entity *entt : entities) {
                entt->getStep()();
            }
        };
        target.getLateStep() += [&]() {
            for (Entity *entt : entities) {
                entt->getStep()();
            }
        };
    }

    const std::vector<Entity *> &Scene::getEntities() const {
        return entities;
    }
}