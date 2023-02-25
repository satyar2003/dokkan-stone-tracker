#include "../header/events.h"
#include <iostream>

using namespace std;

Events::Events() {
    addEvent();
}

Events::~Events() {}

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
    cout << "Choose an option: ";
    cin >> input;

    string name, x;
    int stones = 0;
    cout << endl << "Enter the number of stones from the event: ";
    cin >> stones;
    cout << "Enter the event name: ";
    cin >> x;
    getline(cin, name);
    name = x + name;
    
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
        default:
            type = invalid;
            cout << "Invalid event type" << endl;
            break;
    }
}