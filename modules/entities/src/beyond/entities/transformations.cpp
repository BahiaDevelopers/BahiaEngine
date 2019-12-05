#include <beyond/entities/transformations.h>

namespace beyond {

    Transform::Transform() = default;

    const std::optional<Translation> &Transform::getTranslation() const {
        return translation;
    }

    const std::optional<Rotation> &Transform::getRotation() const {
        return rotation;
    }

    const std::optional<Scale> &Transform::getScale() const {
        return scale;
    }
}