#include "../header/table.h"
#include <iostream>
#include <iomanip>

using namespace std;

Table::Table() {}

Table::~Table() {}

// Prints dividing line 10 characters longer than inputted int [based on columnWidth variable from outputTable()]
void printDivider(int);
// Prints all events of a certain even types with corresponding stone count 
void printEventType(int, vector<Events>, eventType, int &);

// Prints table with total stones divided by category
void Table::outputTable(int currentStones, int days, Weekend w, vector<Events> e) {
    int totalStones = 0;
    int columnWidth = 30;
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventName().size() + 5 > columnWidth) {
            columnWidth = e.at(i).getEventName().size() + 5;
        }
    }
    
    cout << left << setw(columnWidth) << "Current Stones" << currentStones << endl;
    cout << left << setw(columnWidth) << "Weekend Stones" << w.getWeekendStones() + w.stonesFromExtraDays() << endl;
    totalStones += currentStones + w.getWeekendStones() + w.stonesFromExtraDays();
    printDivider(columnWidth);

    cout << left << setw(columnWidth) << "Login Bonus" << days << endl;
    cout << left << setw(columnWidth) << "Special Missions" << days << endl;
    totalStones += days*2;
    printDivider(columnWidth);

    printEventType(columnWidth, e, storyEvent, totalStones);
    printEventType(columnWidth, e, dbStory, totalStones);
    printEventType(columnWidth, e, strikeEvent, totalStones);
    printEventType(columnWidth, e, dokkanEvent, totalStones);
    printEventType(columnWidth, e, ultimateClash, totalStones);
    printEventType(columnWidth, e, primeBattle, totalStones);
    printEventType(columnWidth, e, EZA, totalStones);
    printEventType(columnWidth, e, other, totalStones);

    cout << left << setw(columnWidth) << "Total Stones" << totalStones << endl;
}

void Table::outputTextFile (ofstream& of) {
    of << "Test";
}

void printDivider(int x) {
    for (int i = 0; i < x + 10; ++i) {
        cout << "-";
    }
    cout << endl;
}

void printEventType(int x, vector<Events> e, eventType et, int &total) {
    bool b = false;
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == et) {
            cout << left << setw(x) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            total += e.at(i).getStoneCount();
            b = true;
        }
    }
    if (b) printDivider(x);
}