#ifndef BEYONDENGINE_SCENE_H
#define BEYONDENGINE_SCENE_H

#include <beyond/event.h>
#include <beyond/application.h>

namespace beyond {
    class Entity;

    class Scene : public Extension<Application> {
    private:
        std::vector<Entity *> entities;
    public:
        void addEntity(Entity *entity);

        void apply(Application &target) override;

        const std::vector<Entity *> &getEntities() const;
    };
}
#endif //BEYONDENGINE_SCENE_H
