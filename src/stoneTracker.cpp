#include <iostream>
#include <string>
#include <vector>
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

    int choice = 1;
    vector<Events> eventList;
    while (choice != 0) {
        cout << endl;
        cout << "(1) Add an event" << endl;
        cout << "(2) Output total amount of stones" << endl;
        cout << "(3) Exit the program" << endl;
        cout << "Choose an option: ";
        cin >> choice;

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
                    t.outputTable(currentStones, days, w);
                    break;
                }
            case 3:
                choice = 0;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }

    return 0;
}