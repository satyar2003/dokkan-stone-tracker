#include "../header/events.h"
#include <iostream>
#include <limits>

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

void Events::setStoneCount(int s) {
    stoneCount = s;
}

void Events::addEvent() {
    cout << endl << "Enter the number of stones from the event: ";
    cin >> stoneCount;
    bool b = true;
    while(b) {
        if(cin.good()) b = false;
        else {
            cin.clear();
            cout << "Invalid input" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << endl << "Enter the number of stones from the event: ";
            cin >> stoneCount;
        }
    }

    string x;
    cout << "Enter the event name: ";
    cin >> x;
    b = true;
    while(b) {
        if(cin.good()) b = false;
        else {
            cin.clear();
            cout << "Invalid input" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter the event name: ";
            cin >> x;
        }
    }
    getline(cin, eventName);
    eventName = x + eventName;
}