
#ifndef BEYONDENGINE_CAMERA_H
#define BEYONDENGINE_CAMERA_H

#include <beyond/entities/entity.h>
#include <beyond/entities/transformations.h>
#include <beyond/gl/traits/drawable.h>

namespace beyond {
    class Camera : public Trait {
        void apply(Entity &target) override {
            target.ensureHas<Transform>();
            target.getLateStep() += [&]() {
                for (Entity *entity:target.getScene()->getEntities()) {
                    auto drawable = entity->findExtension<Drawable>();
                    if (drawable != nullptr) {
                        drawable->draw();
                    }
                }
            };
        }
    };
}
#endif
