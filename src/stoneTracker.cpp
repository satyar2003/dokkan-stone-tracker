#include <iostream>
#include <string>
#include "../header/weekend.h"
#include "../header/table.h"

using namespace std;

int main() {
    int currentStones, totalStones, days;
    cout << "Enter the number of dragon stones you currently have: ";
    cin >> currentStones;
    cout << "Enter the number of days you want to save: ";
    cin >> days;

    Weekend w = Weekend(days);
    totalStones += currentStones + 2*days + w.getWeekendStones() + w.stonesFromExtraDays();

    Table t = Table();
    cout << endl;
    t.outputTable(currentStones, days, w);

    return 0;
}