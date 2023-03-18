#include "../header/events.h"
#include <iostream>
#include <limits>

using namespace std;

Events::Events() {
    addEvent();
}

Events::Events(string name, int stones) {
    eventName = name;
    stoneCount = stones;
}

Events::~Events() {}

string Events::getEventName() {
    return eventName;
}

void Events::setEventName(string s) {
    eventName = s;
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

void Events::updateEvent() {
    bool b = true;
    char c;
    cout << "Would you like to update the event name? (y/n) ";
    cin >> c;
    while(b) {
        if(cin.good() && (c == 'y' || c == 'Y' || c == 'N' || c == 'n')) b = false;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << endl << "Invalid input" << endl;
            cout << "Would you like to update the event name? (y/n) ";
            cin >> c;
        }
    }
    if (c == 'y' || c == 'Y') {
        string newName;
        cout << "Enter the new event name: ";
        cin.ignore();
        getline(cin, newName);
        setEventName(newName);
    }

    b = true;
    c = 'a';
    cout << "Would you like to update the event stone count? (y/n) ";
    cin >> c;
    while(b) {
        if(cin.good() && (c == 'y' || c == 'Y' || c == 'N' || c == 'n')) b = false;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << endl << "Invalid input" << endl;
            cout << "Would you like to update the event stone count? (y/n) ";
            cin >> c;
        }
    }
    if (c == 'y' || c == 'Y') {
        int newStoneCount;
        cout << "Enter the new stone count: ";
        cin >> newStoneCount;
        b = true;
        while(b) {
            if(cin.good()) b = false;
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << endl << "Invalid input" << endl;
                cout << "Enter the new stone count: ";
                cin >> newStoneCount;
            }
        }
        setStoneCount(newStoneCount);
    }
}