#ifndef WEEKEND_H
#define WEEKEND_H

#include <time.h>

class Weekend {
    private:
        int weeks;
        int weekendStones;
        int extraDays;
        int extraStones;
    public:
        Weekend(int);
        ~Weekend();
        int getWeekendStones();
        int stonesFromExtraDays();
};

#endif