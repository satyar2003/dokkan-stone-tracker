#ifndef EVENTS_H
#define EVENTS_H

#include <string>

class Events {
    private:
        std::string eventName;
        int stoneCount;
    public:
        Events();
        Events(std::string, int);
        ~Events();
        std::string getEventName();
        int getStoneCount();
        void setStoneCount(int);
        void addEvent();
};

#endif