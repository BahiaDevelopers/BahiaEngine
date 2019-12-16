

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

        uint8_t getElementSize() const;
    };

    template<typename T>
    struct Layout {
    private:
        std::vector<T> elements;
    protected:
        virtual void onAdded(const T &element) {

        }

    public:
        const std::vector<T> &getElements() const {
            return elements;
        }

        template<typename ...A>
        void emplace(A... args) {
            T &element = elements.emplace_back(args...);
            onAdded(element);
        }

    };
}
#endif