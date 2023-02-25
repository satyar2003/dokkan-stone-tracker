#ifndef EVENTS_H
#define EVENTS_H

#include <string>

enum eventType { storyEvent };

class Events {
    private:
        std::string eventName;
        int stoneCount;
        eventType eventType;
    public:
        Events(std::string, int);
        ~Events();
        void addEvent();
};

#endif