#ifndef TABLE_H
#define TABLE_H

#include "weekend.h"
#include "events.h"

class Table {
    public:
        Table();
        ~Table();
        void outputTable(int, int, Weekend);
};

#endif