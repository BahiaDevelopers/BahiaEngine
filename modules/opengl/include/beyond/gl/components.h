#ifndef BEYONDENGINE_COMPONENTS_H
#define BEYONDENGINE_COMPONENTS_H

#include <beyond/entities/entity.h>

namespace beyond {
    class Drawable : public Extension<Entity> {
    public:
        void apply(Entity &target) override {

        }
    };
}
#endif