#include "../header/weekend.h"

using namespace std;

Weekend::Weekend(int days) {
    weeks = days/7;
    weekendStones = weeks*2;
    extraDays = days - weeks*7;
    extraStones = 0;
}

Weekend::~Weekend() {}

int Weekend::getWeekendStones() {
    return weekendStones;
}

int Weekend::stonesFromExtraDays() {
    extraStones = 0;
    time_t t = time(0);
    struct tm *ptr = gmtime(&t);
    switch(ptr->tm_wday) {
        case 0:
            if (extraDays > 0) {
                ++extraStones;
            }
            break;
        case 1:
            if (extraDays == 6) {
                ++extraStones;
            }
            break;
            
        case 2:
            if (extraDays == 5) {
                ++extraStones;
            }
            else if (extraDays == 6) {
                extraStones += 2;
            }
            break;
            
        case 3:
            if (extraDays == 4) {
                ++extraStones;
            }
            else if (extraDays == 5) {
                extraStones += 2;
            }
            break;
        case 4:
            if (extraDays == 3) {
                ++extraStones;
            }
            else if (extraDays == 4) {
                extraStones += 2;
            }
            break;
        case 5:
            if (extraDays == 2) {
                ++extraStones;
            }
            else if (extraDays == 3) {
                extraStones += 2;
            }
            break;
        case 6:
            if (extraDays == 1) {
                ++extraStones;
            }
            else if (extraDays > 1) {
                extraStones += 2;
            }
            break;
    }
    return extraStones;
}