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

eventType Events::getEventType() {
    return type;
}

void Events::setStoneCount(int s) {
    stoneCount = s;
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
    bool b = true;
    while(b) {
        if(cin.good()) b = false;
        else {
            cin.clear();
            cout << endl << "Invalid input";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
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
        }
    }

    if (input == 7) {
        cout << endl << "(1) TUR EZA" << endl;
        cout << "(2) LR EZA" << endl;
        cout << "Choose an option: ";
        cin >> input;
        b = true;
        while(b) {
        if(cin.good()) {
            if (input >= 1 && input <=2) b = false;
        }
        else {
            cin.clear();
            cout << endl << "Invalid input";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << endl << "(1) TUR EZA" << endl;
            cout << "(2) LR EZA" << endl;
            cout << "Choose an option: ";
            cin >> input;
        }
        if (input == 2) { cout << "34 stones from the event" << endl; stoneCount = 34; }
        else { cout << "33 stones from the event" << endl; stoneCount = 33; }
        }
        input = 7;
    }

    switch (input) {
        case 3:
            stoneCount = 20;
            cout << "20 stones from the event" << endl;
            break;
        case 4:
            stoneCount = 2;
            cout << "2 stones from the event" << endl;
            break;
        case 5:
            stoneCount = 31;
            cout << "31 stones from the event" << endl;
            break;
        case 6: 
            stoneCount = 3;
            cout << "3 stones from the event" << endl;
            break;
    }

    if (input == 1 || input == 2 || input == 8) {
        cout << endl << "Enter the number of stones from the event: ";
        cin >> stoneCount;
        b = true;
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