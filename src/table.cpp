#include "../header/table.h"
#include <iostream>
#include <iomanip>

using namespace std;

Table::Table() {}

Table::~Table() {}

void Table::outputTable(int currentStones, int days, Weekend w, vector<Events> e) {
    int totalStones = 0;
    
    cout << left << setw(40) << "Current Stones" << currentStones << endl;
    cout << left << setw(40) << "Weekend Stones" << w.getWeekendStones() + w.stonesFromExtraDays() << endl;
    totalStones += currentStones + w.getWeekendStones() + w.stonesFromExtraDays();
    cout << "------------------------------------------------------" << endl;

    cout << left << setw(40) << "Login Bonus" << days << endl;
    cout << left << setw(40) << "Special Missions" << days << endl;
    totalStones += days*2;
    cout << "------------------------------------------------------" << endl;

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == storyEvent) {
            cout << left << setw(40) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == storyEvent) {
            cout << "------------------------------------------------------" << endl;
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == dbStory) {
            cout << left << setw(40) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == dbStory) {
            cout << "------------------------------------------------------" << endl;
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == strikeEvent) {
            cout << left << setw(40) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == strikeEvent) {
            cout << "------------------------------------------------------" << endl;
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == dokkanEvent) {
            cout << left << setw(40) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == dokkanEvent) {
            cout << "------------------------------------------------------" << endl;
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == ultimateClash) {
            cout << left << setw(40) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == ultimateClash) {
            cout << "------------------------------------------------------" << endl;
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == primeBattle) {
            cout << left << setw(40) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == primeBattle) {
            cout << "------------------------------------------------------" << endl;
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == EZA) {
            cout << left << setw(40) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == EZA) {
            cout << "------------------------------------------------------" << endl;
            break;
        }
    }

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == other) {
            cout << left << setw(40) << e.at(i).getEventName() << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == other) {
            cout << "------------------------------------------------------" << endl;
            break;
        }
    }

    cout << left << setw(40) << "Total Stones" << totalStones << endl;
}