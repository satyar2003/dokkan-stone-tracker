#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <fstream>
#include "weekend.h"
#include "events.h"

class Table {
    public:
        Table();
        ~Table();
        void outputTable(int, int, Weekend, std::vector<Events>);
        void outputTextFile (std::ofstream&);
};

#endif