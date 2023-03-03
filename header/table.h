#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <fstream>
#include "weekend.h"
#include "events.h"

class Table {
    private:
        std::vector<std::string> tableLines;
    public:
        Table();
        ~Table();
        void fillTable(int, int, Weekend, std::vector<Events>);
        void outputTable();
        void outputTextFile (std::ofstream&);
};

#endif