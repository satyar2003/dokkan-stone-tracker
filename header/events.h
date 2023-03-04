#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <vector>

enum eventType { invalid, storyEvent, dbStory, strikeEvent, dokkanEvent, ultimateClash, primeBattle, EZA, other };

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
        void setStoneCount(int);
        void addEvent();
        void completeEvent(vector<Events> &);
        void removeEvent(vector<Events> &);
};

#endif