#include "../header/events.h"

using namespace std;

Events::Events(string name, int count) {
    eventName = name;
    stoneCount = count;
    eventType = NULL;
}

Events::~Events() {}

void Events::addEvent() {
    int input = 0;
    cout << "(1) Add Story Event" << endl;
    cout << "Choose an option: ";
    cin >> input;
    
    switch(input) {
        case 1:
            eventType = storyEvent;
            break;
    }
}