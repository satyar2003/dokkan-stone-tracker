#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <ctype.h>
#include "../header/table.h"

using namespace std;

void completeEvent(vector<Events> &);
void removeEvent(vector<Events> &);
void updateEvent(vector<Events> &);
void clearIncorrectInput(istream&, string);

int main() {
    bool b = true;
    char c;
    string in = "";
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
    vector<Events> eventList;
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
        string x;
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
                    size_t pos = line.find("   ");
                    for (int i = static_cast<int>(pos); i < line.size(); ++i) {
                        if (isdigit(line.at(i)) || line.at(i) == '-') {
                            stone += line.at(i);
                        }
                    }
                    currentStones = stoi(stone);
                }
                else if (line.substr(0, 11) == "Login Bonus" || line.substr(0, 16) == "Special Missions") {
                    stone = "";
                    size_t pos = line.find("   ");
                    for (int i = static_cast<int>(pos); i < line.size(); ++i) {
                        if (isdigit(line.at(i)) || line.at(i) == '-') {
                            stone += line.at(i);
                        }
                    }
                    days = stoi(stone);
                }
                else if (!(line.substr(0, 10) == "----------" 
                        || line.substr(0, 12) == "Total Stones" 
                        || line.substr(0, 12) == "Total Multis" 
                        || line.substr(0, 14) == "Weekend Stones"
                        || line.substr(0, 25) == "Chance to pull new DFE LR")) {
                    stone = "";
                    size_t pos = line.find("   ");
                    for (int i = static_cast<int>(pos); i < line.size(); ++i) {
                        if (isdigit(line.at(i)) || line.at(i) == '-') {
                            stone += line.at(i);
                        }
                    }
                    eventList.push_back(Events(line.substr(0, pos), stoi(stone)));
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

    Weekend w = Weekend(days);
    Table t = Table();
    int choice = 1;
    while (choice != 0) {
        cout << endl;
        cout << "(1) Add an event" << endl;
        cout << "(2) Output total amount of stones" << endl;
        cout << "(3) Update current stone count" << endl;
        cout << "(4) Update days of saving" << endl;
        cout << "(5) Mark an event as completed" << endl;
        cout << "(6) Remove an event" << endl;
        cout << "(7) Update an event" << endl;
        cout << "(8) Generate text file with total stones" << endl;
        cout << "(9) Remove all completed events" << endl;
        cout << "(10) Exit the program" << endl;
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
            s += "(7) Update an event\n";
            s += "(8) Generate text file with total stones\n";
            s += "(9) Remove all completed events\n";
            s += "(10) Exit the program\n";
            s += "Choose an option: ";
            clearIncorrectInput(cin, s);
            cin >> choice;
        }
    }

    switch (choice) {
        case 1:
            {
                Events e = Events();
                eventList.push_back(e);
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
            if (eventList.size() > 0) {
                updateEvent(eventList);
            }
            else {
                cout << "No events to update" << endl;
            }
            break;
        case 8:
            {
                t.fillTable(currentStones, days, w, eventList);

                b = true;
                cout << "Would you like to name the text file? (y/n) ";
                cin >> c;
                while(b) {
                    if(cin.good() && (c == 'y' || c == 'Y' || c == 'N' || c == 'n')) b = false;
                    else {
                        clearIncorrectInput(cin, "Would you like to input a text file? (y/n) ");
                        cin >> c;
                    }
                }

                if (c == 'y' || c == 'Y') {
                    string txtFileName = "";
                    cout << "Enter what you would like to name the file: ";
                    cin >> txtFileName;
                    if (txtFileName.substr(txtFileName.size() - 4, 4) != ".txt") {
                        txtFileName += ".txt";
                    }
                    ofstream output(txtFileName, ofstream::out | ofstream::trunc);
                    if (output.is_open()) {
                        t.outputTextFile(output);
                        output.close();
                    }
                    else cout << "Problem with opening file" << endl;
                }
                else {
                    if (in == "") {
                        ofstream output("glb_stone_tracker.txt", ofstream::out | ofstream::trunc);
                        if (output.is_open()) {
                            t.outputTextFile(output);
                            output.close();
                        }
                        else cout << "Problem with opening file" << endl;
                    }
                    else {
                        ofstream output(in, ofstream::out | ofstream::trunc);
                        if (output.is_open()) {
                            t.outputTextFile(output);
                            output.close();
                        }
                        else cout << "Problem with opening file" << endl;
                    }
                }

                
            }
            break;
        case 9:
            for (int i = 0; i < eventList.size(); ++i) {
                if(eventList.at(i).getStoneCount() == 0) {
                    eventList.erase(eventList.begin() + i);
                    --i;
                }
            }
            break;
        case 10:
            choice = 0;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }

    return 0;
}

void completeEvent(vector<Events> &e) {
    int option;
    cout << endl;
    for (int i = 0; i < e.size(); ++i) {
        cout << "(" << i + 1 << ") Mark \"" << e.at(i).getEventName() << "\" as completed" << endl;
    }
    cout << "Choose an option: ";
    cin >> option;
    bool b = true;
    while(b) {
        if(cin.good() && (option >= 1 && option <= e.size())) b = false;
            else {
                string s = "";
                for (int i = 0; i < e.size(); ++i) {
                    s += "(" + to_string(i + 1) + ") Mark \"" + e.at(i).getEventName() + "\" as completed\n";
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
        cout << "(" << i + 1 << ") Remove \"" << e.at(i).getEventName() << "\"" << endl;
    }
    cout << "Choose an option: ";
    cin >> option;
    bool b = true;
    while(b) {
        if(cin.good() && (option >= 1 && option <= e.size())) b = false;
            else {
                string s = "";
                for (int i = 0; i < e.size(); ++i) {
                    s += "(" + to_string(i + 1) + ") Remove \"" + e.at(i).getEventName() + "\"\n";
                }
                s += "Choose an option: ";
                clearIncorrectInput(cin, s);
                cin >> option;
            }
            
        } 
    e.erase(e.begin()+option-1);
    }

void updateEvent(vector<Events> &e) {
    int option;
    cout << endl;
    for (int i = 0; i < e.size(); ++i) {
        cout << "(" << i + 1 << ") Update \"" << e.at(i).getEventName() << "\"" << endl;
    }
    cout << "Choose an option: ";
    cin >> option;
    bool b = true;
    while(b) {
        if(cin.good() && (option >= 1 && option <= e.size())) b = false;
            else {
                string s = "";
                for (int i = 0; i < e.size(); ++i) {
                    s += "(" + to_string(i + 1) + ") Update \"" + e.at(i).getEventName() + "\"\n";
                }
                s += "Choose an option: ";
                clearIncorrectInput(cin, s);
                cin >> option;
            }
            
        } 
    e.at(option-1).updateEvent();
}

void clearIncorrectInput(istream& in, string msg) {
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << endl << "Invalid input" << endl;
    cout << msg;
}
