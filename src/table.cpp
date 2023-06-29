#include "../header/table.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

Table::Table() {}

Table::~Table() {}

// Prints dividing line 10 characters longer than column width
string printDivider(int);

// Fills tableLines vector with total stones from each source
void Table::fillTable(int currentStones, int days, Weekend w, vector<Events> e) {
    tableLines.clear();
    int totalStones = 0;
    int columnWidth = 30;
    string spaces, line;
    for (int i = 0; i < e.size(); ++i) {
        if (e.at(i).getEventName().size() + 5 > columnWidth) {
            columnWidth = e.at(i).getEventName().size() + 5;
        }
    }

    for (int i = 0; i < columnWidth - 14; ++i) {
        spaces += " ";
    }
    tableLines.push_back("Current Stones" + spaces + to_string(currentStones));
    tableLines.push_back("Weekend Stones" + spaces + to_string(w.getWeekendStones() + w.stonesFromExtraDays()));
    totalStones += currentStones + w.getWeekendStones() + w.stonesFromExtraDays();
    tableLines.push_back(printDivider(columnWidth));

    spaces = "";
    for (int i = 0; i < columnWidth - 11; ++i) {
        spaces += " ";
    }
    tableLines.push_back("Login Bonus" + spaces + to_string(days));

    spaces = "";
    for (int i = 0; i < columnWidth - 16; ++i) {
        spaces += " ";
    }
    tableLines.push_back("Special Missions" + spaces + to_string(days));
    totalStones += days*2;
    tableLines.push_back(printDivider(columnWidth));

    for (int i = 0; i < e.size(); ++i) {
        spaces = "";
        for (int j = 0; j < columnWidth - e.at(i).getEventName().size(); ++j) {
            spaces += " ";
        }
        tableLines.push_back(e.at(i).getEventName() + spaces + to_string(e.at(i).getStoneCount()));
        totalStones += e.at(i).getStoneCount();
    }
    if (e.size() != 0) tableLines.push_back(printDivider(columnWidth));

    spaces = "";
    for (int i = 0; i < columnWidth - 12; ++i) {
        spaces += " ";
    }
    tableLines.push_back("Total Stones" + spaces + to_string(totalStones));
    tableLines.push_back("Total Multis" + spaces + to_string(totalStones/50));

    double chance = (1 - pow(.995, (totalStones/50)*10)) * 100;
    stringstream st;
    st << fixed << setprecision(2) << chance;
    string l = st.str();
    spaces = "";
    for (int i = 0; i < columnWidth - 25; ++i) {
        spaces += " ";
    }
    tableLines.push_back("Chance to pull new DFE LR" + spaces + l + "%");
}

// Prints table with total stones from each source
void Table::outputTable() {
    for (int i = 0; i < tableLines.size(); ++i) {
        cout << tableLines.at(i) << endl;
    }
}

// Creates text file with total stones from each source
void Table::outputTextFile (ofstream& of) {
    for (int i = 0; i < tableLines.size() - 1; ++i) {
        of << tableLines.at(i) << endl;
    }
    of << tableLines.at(tableLines.size() - 1);
}

string printDivider(int x) {
    string s;
    for (int i = 0; i < x + 10; ++i) {
        s += "-";
    }
    return s;
}