#ifndef EVENTS_H
#define EVENTS_H

#include <string>

enum eventType { invalid, storyEvent, dbStory, strikeEvent, dokkanEvent, ultimateClash, primeBattle, EZA };

class Events {
    private:
        std::string eventName;
        int stoneCount;
        eventType type;
    public:
        Events();
        ~Events();
        std::string getEventName();
        int getStoneCount();
        eventType getEventType();
        void addEvent();
};

#endif