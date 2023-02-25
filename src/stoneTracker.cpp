#include <iostream>
#include <string>
#include "../header/weekend.h"

using namespace std;

int main() {
    int totalStones, days;
    cout << "Enter the number of dragon stones you currently have: ";
    cin >> totalStones;
    cout << "Enter the number of days you want to save: ";
    cin >> days;

    Weekend w = Weekend(days);
    totalStones += 2*days + w.getWeekendStones() + w.stonesFromExtraDays();
    
    cout << "You will have " << totalStones << " stones by that time." << endl;

    return 0;
}