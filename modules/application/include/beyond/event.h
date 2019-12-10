#ifndef BEYONDENGINE_EVENT_H
#define BEYONDENGINE_EVENT_H


#include <functional>
#include <vector>
#include <utility>
#include <algorithm>

namespace beyond {

    template<typename ...T>
    class Event {
    public:
        typedef std::function<void(T...)> EventListener;
    private:
        std::vector<EventListener> listeners;
    public:

        void operator+=(EventListener listener) {
            listeners.push_back(listener);
        }

        void operator-=(EventListener listener) {
            listeners.erase(std::remove(listeners.begin(), listeners.end(), listener));
        }

        void operator()(T... args) {
            for (EventListener listener : listeners) {
                listener(args...);
            }
        }
    };
};

#endif