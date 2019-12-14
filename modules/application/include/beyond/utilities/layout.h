

#ifndef BEYONDENGINE_LAYOUT_H
#define BEYONDENGINE_LAYOUT_H

#include <vector>
#include <cstdint>

namespace beyond {
    struct LayoutElement {
    private:
        /**
         * The bytes length of a single item.
         */
        uint8_t elementLength;
        /**
         * How many items are in this element.
         */
        uint8_t elementCount;
    public:
        LayoutElement(
                uint8_t elementLength,
                uint8_t elementCount
        );

        uint8_t getElementLength() const;

        uint8_t getElementCount() const;

        uint8_t getElementSize();
    };

    template<typename T>
    struct Layout {
    public:


    private:
        std::vector<T> elements;
    public:
        template<typename ...A>
        void emplace_element(A... args) {
            elements.emplace_back(std::forward(args...));
        }
    };
}
#endif