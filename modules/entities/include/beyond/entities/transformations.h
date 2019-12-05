#ifndef BEYONDENGINE_TRANSFORMATIONS_H
#define BEYONDENGINE_TRANSFORMATIONS_H

#include <beyond/entities/entity.h>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <string>
#include <optional>

namespace beyond {
    template<typename T>
    class Transformation : public Extension<Entity> {
    private:
        T value;
    public:
        Transformation(T value) : value(value) {}

        T getValue() const {
            return value;
        }

        void setValue(T newValue) {
            value = newValue;
        }

        void apply(Entity &target) override {

        }
    };


    class Translation : public Transformation<glm::vec3> {
    };

    class Rotation : public Transformation<glm::quat> {
    };

    class Scale : public Transformation<glm::vec3> {
    };

    class Transform : public Extension<Entity> {
    private:
        std::optional<Translation> translation;
        std::optional<Rotation> rotation;
        std::optional<Scale> scale;
    public:
        Transform();

        const std::optional<Translation> &getTranslation() const;

        const std::option<Rotation> &getRotation() const;

        const std::option<Scale> &getScale() const;
    };
}
#endif
