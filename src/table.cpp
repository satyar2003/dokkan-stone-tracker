#include "../header/table.h"
#include <iostream>
#include <iomanip>

using namespace std;

Table::Table() {}

Table::~Table() {}

void Table::outputTable(int currentStones, int days, Weekend w) {
    cout << left << setw(20) << "Current Stones" << currentStones << endl;
    cout << left << setw(20) << "Weekend Stones" << w.getWeekendStones() + w.stonesFromExtraDays() << endl;
    cout << "---------------------------" << endl;
    cout << left << setw(20) << "Login Bonus" << days << endl;
    cout << left << setw(20) << "Special Missions" << days << endl;
    cout << "---------------------------" << endl;
    cout << left << setw(20) << "Total Stones" << currentStones + w.getWeekendStones() + w.stonesFromExtraDays() + days*2 << endl;
}