#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "../header/table.h"

using namespace std;

void completeEvent(vector<Events> &);
void removeEvent(vector<Events> &);
void clearIncorrectInput(istream&, string);

int main() {
    bool b = true;
    char c;
    cout << "Would you like to input a text file? (y/n) ";
    cin >> c;
    while(b) {
        if(cin.good() && (c == 'y' || c == 'Y' || c == 'N' || c == 'n')) b = false;
        else {
            clearIncorrectInput(cin, "Would you like to input a text file? (y/n) ");
            cin >> c;
        }
    }
    int currentStones = 0;
    int days = 0;
    if (c == 'n' || c == 'N') {
        cout << "Enter the number of dragon stones you currently have: ";
        cin >> currentStones;
        b = true;
        while(b) {
            if(cin.good()) b = false;
            else {
                clearIncorrectInput(cin, "Enter the number of dragon stones you currently have: ");
                cin >> currentStones;
            }
        }

        cout << "Enter the number of days you want to save: ";
        cin >> days;
        b = true;
        while(b) {
            if(cin.good()) b = false;
            else {
                clearIncorrectInput(cin, "Enter the number of days you want to save: ");
                cin >> days;
            }
        }
    }
    else {
        string in, x;
        cout << "Input text file: ";
        cin.ignore();
        getline(cin, in);
        b = true;
        while(b) {
            if(cin.good() && in.size() >= 4) {
                if (in.substr(in.size() - 4, 4) == ".txt") {
                    b = false;
                }
                else {
                    clearIncorrectInput(cin, "Input text file: ");
                    getline(cin, in);
                }
            } 
            else {
                clearIncorrectInput(cin, "Input text file: ");
                getline(cin, in);
            }
        }

        string line;
        ifstream input(in);
        if(input.is_open()) {
            while(getline(input, line)) {
                string stone = "";
                if (line.substr(0, 14) == "Current Stones") {
                    for (int i = 14; i < line.size(); ++i) {
                        if (line.at(i) != ' ') {
                            stone += line.at(i);
                        }
                    }
                    currentStones = stoi(stone);
                }
                else if (line.substr(0, 11) == "Login Bonus" || line.substr(0, 16) == "Special Missions") {
                    stone = "";
                    for (int i = 16; i < line.size(); ++i) {
                        if (line.at(i) != ' ') {
                            stone += line.at(i);
                        }
                    }
                    days = stoi(stone);
                }
            }
            input.close();
        }
        else {
            int currentStones = 0;
            int days = 0;
            cout << "Error opening file. Setting all values to 0." << endl;
        }
    }

    int choice = 1;
    Weekend w = Weekend(days);
    vector<Events> eventList;
    Table t = Table();
    while (choice != 0) {
        cout << endl;
        cout << "(1) Add an event" << endl;
        cout << "(2) Output total amount of stones" << endl;
        cout << "(3) Update current stone count" << endl;
        cout << "(4) Update days of saving" << endl;
        cout << "(5) Mark an event as completed" << endl;
        cout << "(6) Remove an event" << endl;
        cout << "(7) Generate text file with total stones" << endl;
        cout << "(8) Exit the program" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        b = true;
        while(b) {
        if(cin.good()) b = false;
        else {
            string s = "(1) Add an event\n";
            s += "(2) Output total amount of stones\n";
            s += "(3) Update current stone count\n";
            s += "(4) Update days of saving\n";
            s += "(5) Mark an event as completed\n";
            s += "(6) Remove an event\n";
            s += "(7) Generate text file with total stones\n";
            s += "(8) Exit the program\n";
            s += "Choose an option: ";
            clearIncorrectInput(cin, s);
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
                t.fillTable(currentStones, days, w, eventList);
                cout << endl;
                t.outputTable();
                break;
            }
        case 3:
            b = true;
            cout << endl << "Enter new stone count: ";
            cin >> currentStones;
            while (b) {
                if (cin.good()) b = false;
                else {
                    clearIncorrectInput(cin, "Enter new stone count: ");
                    cin >> currentStones;
                }
            }
            break;
        case 4:
            b = true;
            cout << endl << "Enter number of days you will save: ";
            cin >> days;
            while (b) {
                if (cin.good()) b = false;
                else {
                    clearIncorrectInput(cin, "Enter number of days you will save: ");
                    cin >> days;
                }
            }
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
            if (eventList.size() > 0) {
                removeEvent(eventList);
            }
            else {
                cout << "No events to remove" << endl;
            }
            break;
        case 7:
            {
                t.fillTable(currentStones, days, w, eventList);
                ofstream output("glb_stone_tracker.txt", ofstream::out | ofstream::trunc);
                if (output.is_open()) {
                    t.outputTextFile(output);
                    output.close();
                }
                else cout << "Problem with opening file" << endl;
            }
            break;
        case 8:
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
        if(cin.good() && (option >= 1 && option <= e.size())) b = false;
            else {
                string s = "";
                for (int i = 0; i < e.size(); ++i) {
                    s += "(" + to_string(i + 1) + ") Mark " + e.at(i).getEventName() + " as completed\n";
                }
                s += "Choose an option: ";
                clearIncorrectInput(cin, s);
                cin >> option;
            }
            
        }
    e.at(option - 1).setStoneCount(0);
    }

void removeEvent(vector<Events> &e) {
    int option;
    cout << endl;
    for (int i = 0; i < e.size(); ++i) {
        cout << "(" << i + 1 << ") Remove " << e.at(i).getEventName() << endl;
    }
    cout << "Choose an option: ";
    cin >> option;
    bool b = true;
    while(b) {
        if(cin.good() && (option >= 1 && option <= e.size())) b = false;
            else {
                string s = "";
                for (int i = 0; i < e.size(); ++i) {
                    s += "(" + to_string(i + 1) + ") Remove " + e.at(i).getEventName() + "\n";
                }
                s += "Choose an option: ";
                clearIncorrectInput(cin, s);
                cin >> option;
            }
            
        } 
    e.erase(e.begin()+option-1);
    }

void clearIncorrectInput(istream& in, string msg) {
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << endl << "Invalid input" << endl;
    cout << msg;
}
