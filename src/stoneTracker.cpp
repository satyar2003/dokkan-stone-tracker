#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main() {
    int stones, days;
    cout << "Enter the number of dragon stones you currently have: ";
    cin >> stones;
    cout << "Enter the number of days you want to save: ";
    cin >> days;

    stones += 2*days;

    cout << "You will have " << stones << " stones by that time." << endl;

    return 0;
}