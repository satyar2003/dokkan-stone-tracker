#include "../header/events.h"
#include <iostream>

using namespace std;

Events::Events() {
    addEvent();
}

Events::~Events() {}

string Events::getEventName() {
    return eventName;
}

int Events::getStoneCount() {
    return stoneCount;
}

eventType Events::getEventType() {
    return type;
}

void Events::addEvent() {
    int input = 0;
    cout << endl << "(1) Add Story Event" << endl;
    cout << "(2) Add Dragon Ball Story" << endl;
    cout << "(3) Add Super Strike Event" << endl;
    cout << "(4) Add Dokkan Event" << endl;
    cout << "(5) Add Virtual Dokkan Ultimate Clash" << endl;
    cout << "(6) Add Prime Battle Event" << endl;
    cout << "(7) Add Extreme Z-Battle" << endl;
    cout << "(8) Other" << endl;
    cout << "Choose an option: ";
    cin >> input;

    string x;
    cout << endl << "Enter the number of stones from the event: ";
    cin >> stoneCount;
    cout << "Enter the event name: ";
    cin >> x;
    getline(cin, eventName);
    eventName = x + eventName;
    
    switch(input) {
        case 1:
            type = storyEvent;
            break;
        case 2:
            type = dbStory;
            break;
        case 3: 
            type = strikeEvent;
            break;
        case 4:
            type = dokkanEvent;
            break;
        case 5:
            type = ultimateClash;
            break;
        case 6:
            type = primeBattle;
            break;
        case 7:
            type = EZA;
            break;
        case 8:
            type = other;
            break;
        default:
            type = invalid;
            cout << "Invalid event type" << endl;
            break;
    }
}