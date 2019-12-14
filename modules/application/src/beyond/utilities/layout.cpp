#include <beyond/utilities/layout.h>

namespace beyond {

    uint8_t LayoutElement::getElementLength() const {
        return elementLength;
    }

    uint8_t LayoutElement::getElementCount() const {
        return elementCount;
    }

    uint8_t LayoutElement::getElementSize() {
        return elementLength * elementCount;
    }

    LayoutElement::LayoutElement(
            uint8_t elementLength,
            uint8_t elementCount
    ) : elementLength(elementLength),
        elementCount(elementCount) {

    }
}