
#ifndef BEYONDENGINE_CAMERA_H
#define BEYONDENGINE_CAMERA_H

#include <beyond/entities/entity.h>
#include <beyond/gl/t
#include <beyond/entities/transformations.h>

namespace beyond {
    class Camera : public Trait {
        void apply(Entity &target) override {
            target.ensureHas<Transform>();
            target.getScene()->getRender() += []() {

            }
        }
    };
}
#endif
