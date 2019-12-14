#include <beyond/entities/transformations.h>

namespace beyond {

    Transform::Transform() = default;

    const std::optional<Translation *> &Transform::getTranslation() const {
        return translation;
    }

    const std::optional<Rotation *> &Transform::getRotation() const {
        return rotation;
    }

    const std::optional<Scale *> &Transform::getScale() const {
        return scale;
    }

    template<typename T>
    void check_assign_to_transform(std::optional<T *> &into, Trait *trait) {
        T *candidate = dynamic_cast<T *>(trait);
        if (candidate != nullptr) {
            into = candidate;
        }
    }

    void Transform::apply(Entity &target) {
        target.getOnExtensionApplied() += [&](Trait *trait) {
            check_assign_to_transform<Translation>(translation, trait);
            check_assign_to_transform<Rotation>(rotation, trait);
            check_assign_to_transform<Scale>(scale, trait);
        };
    }
}