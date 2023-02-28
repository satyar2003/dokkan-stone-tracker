#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "../header/table.h"

using namespace std;

void completeEvent(vector<Events> &);

int main() {
    int currentStones, totalStones, days;
    cout << "Enter the number of dragon stones you currently have: ";
    cin >> currentStones;
    bool b = true;
    while(b) {
        if(cin.good()) b = false;
        else {
            cin.clear();
            cout << "Invalid input" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter the number of dragon stones you currently have: ";
            cin >> currentStones;
        }
    }

    cout << "Enter the number of days you want to save: ";
    cin >> days;
    b = true;
    while(b) {
        if(cin.good()) b = false;
        else {
            cin.clear();
            cout << "Invalid input" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter the number of days you want to save: ";
            cin >> days;
        }
    }

    int choice = 1;
    Weekend w = Weekend(days);
    vector<Events> eventList;
    while (choice != 0) {
        cout << endl;
        cout << "(1) Add an event" << endl;
        cout << "(2) Output total amount of stones" << endl;
        cout << "(3) Update current stone count" << endl;
        cout << "(4) Update days of saving" << endl;
        cout << "(5) Mark an event as completed" << endl;
        cout << "(6) Exit the program" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        b = true;
        while(b) {
        if(cin.good()) b = false;
        else {
            cin.clear();
            cout << endl << "Invalid input";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << endl;
            cout << "(1) Add an event" << endl;
            cout << "(2) Output total amount of stones" << endl;
            cout << "(3) Update current stone count" << endl;
            cout << "(4) Update days of saving" << endl;
            cout << "(5) Mark an event as completed" << endl;
            cout << "(6) Exit the program" << endl;
            cout << "Choose an option: ";
            cin >> choice;
        }
    }

    switch (choice) {
        case 1:
            {
                Events e = Events();
                if (e.getEventType() != invalid) {
                    eventList.push_back(e);
                }
                break;
            }
        case 2:
            {
                Table t = Table();
                cout << endl;
                t.outputTable(currentStones, days, w, eventList);
                break;
            }
        case 3:
            cout << endl << "Enter new stone count: ";
            cin >> currentStones;
            break;
        case 4:
            cout << endl << "Enter number of days you will save: ";
            cin >> days;
            w = Weekend(days);
            break;
        case 5:
            if (eventList.size() > 0) {
                completeEvent(eventList);
            }
            else {
                cout << "No events to complete" << endl;
            }
            break;
        case 6:
            choice = 0;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    return 0;
}

void completeEvent(vector<Events> &e) {
    int option;
    cout << endl;
    for (int i = 0; i < e.size(); ++i) {
        cout << "(" << i + 1 << ") Mark " << e.at(i).getEventName() << " as completed" << endl;
    }
    cout << "Choose an option: ";
    cin >> option;
    bool b = true;
    while(b) {
        if(cin.good()){
            if (option >= 1 || option <= e.size()) b = false;
            else {
                cin.clear();
                cout << "Invalid input" << endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                for (int i = 0; i < e.size() - 1; ++i) {
                    cout << "(" << i + 1 << ") Mark " << e.at(i).getEventName() << " as completed" << endl;
                }
                cout << "(" << e.size() << ") Mark " << e.at(e.size()-1).getEventName() << " as completed";
                cout << "Choose an option: ";
                cin >> option;
            }
            
        } 
        else {
            cin.clear();
            cout << "Invalid input" << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            for (int i = 0; i < e.size() - 1; ++i) {
                cout << "(" << i + 1 << ") Mark " << e.at(i).getEventName() << " as completed" << endl;
            }
            cout << "(" << e.size() << ") Mark " << e.at(e.size()-1).getEventName() << " as completed";
            cout << "Choose an option: ";
            cin >> option;
        }
    }
    e.at(option - 1).setStoneCount(0);
}