#include "../header/table.h"
#include <iostream>
#include <iomanip>

using namespace std;

Table::Table() {}

Table::~Table() {}

void Table::outputTable(int currentStones, int days, Weekend w, vector<Events> e) {
    int totalStones = 0;
    
    cout << left << setw(20) << "Current Stones" << currentStones << endl;
    cout << left << setw(20) << "Weekend Stones" << w.getWeekendStones() + w.stonesFromExtraDays() << endl;
    totalStones += currentStones + w.getWeekendStones() + w.stonesFromExtraDays();
    cout << "---------------------------" << endl;

    cout << left << setw(20) << "Login Bonus" << days << endl;
    cout << left << setw(20) << "Special Missions" << days << endl;
    totalStones += days*2;
    cout << "---------------------------" << endl;

    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventType() == storyEvent) {
            cout << left << setw(20) << e.at(i).getEventName() << " " << e.at(i).getStoneCount() << endl;
            totalStones += e.at(i).getStoneCount();
        }
    }
    cout << "---------------------------" << endl;

    cout << left << setw(20) << "Total Stones" << totalStones << endl;
}