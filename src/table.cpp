#include "../header/table.h"
#include <iostream>
#include <iomanip>

using namespace std;

Table::Table() {}

Table::~Table() {}

// Prints dividing lines 10 characters longer than inputted int
void printDivider(int);

// Prints table with total stones divided by category
void Table::outputTable(int currentStones, int days, Weekend w, vector<Events> e) {
    int totalStones = 0;
    int columnWidth = 30;
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventName().size() + 1 > columnWidth) {
            columnWidth = e.at(i).getEventName().size() + 5;
        }
    }
    
    cout << left << setw(columnWidth) << "Current Stones" << currentStones << endl;
    cout << left << setw(columnWidth) << "Weekend Stones" << w.getWeekendStones() + w.stonesFromExtraDays() << endl;
    totalStones += currentStones + w.getWeekendStones() + w.stonesFromExtraDays();
    printDivider(columnWidth);
    cout << endl;

    cout << left << setw(columnWidth) << "Login Bonus" << days << endl;
    cout << left << setw(columnWidth) << "Special Missions" << days << endl;
    totalStones += days*2;
    printDivider(columnWidth);

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == storyEvent) {
            cout << left << setw(columnWidth) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == storyEvent) {
            printDivider(columnWidth);
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == dbStory) {
            cout << left << setw(columnWidth) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == dbStory) {
            printDivider(columnWidth);
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == strikeEvent) {
            cout << left << setw(columnWidth) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == strikeEvent) {
            printDivider(columnWidth);
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == dokkanEvent) {
            cout << left << setw(columnWidth) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == dokkanEvent) {
            printDivider(columnWidth);
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == ultimateClash) {
            cout << left << setw(columnWidth) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == ultimateClash) {
            printDivider(columnWidth);
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == primeBattle) {
            cout << left << setw(columnWidth) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == primeBattle) {
            printDivider(columnWidth);
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == EZA) {
            cout << left << setw(columnWidth) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == EZA) {
            printDivider(columnWidth);
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == other) {
            cout << left << setw(columnWidth) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == other) {
            printDivider(columnWidth);
            break;
        }
    }

    cout << left << setw(columnWidth) << "Total Stones" << totalStones << endl;
}

void printDivider(int x) {
    for (int i = 0; i < x + 10; ++i) {
        cout << "-";
    }
    cout << endl;
}