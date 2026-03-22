#include <iostream>
using namespace std;

struct stDate {
    short year, month, day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};

short Compare_Dates(stDate date1, stDate date2) {
    if (date1.year > date2.year) return 1;
    if (date1.year < date2.year) return -1;
    if (date1.month > date2.month) return 1;
    if (date1.month < date2.month) return -1;
    if (date1.day > date2.day) return 1;
    if (date1.day < date2.day) return -1;
    return 0;
}

bool Is_Overlap(stPeriod Period1, stPeriod Period2) {
    if (Compare_Dates(Period1.EndDate, Period2.StartDate) == -1)
        return false;

    if (Compare_Dates(Period1.StartDate, Period2.EndDate) == 1)
        return false;

    return true;
}

stDate readData() {
    stDate date;
    cout << "Please enter a Day? "; cin >> date.day;
    cout << "Please enter a Month? "; cin >> date.month;
    cout << "Please enter a Year? "; cin >> date.year;
    return date;
}

int main() {
    stPeriod P1, P2;

    cout << "Enter Period 1:\n";
    cout << "Enter Start Date:\n"; P1.StartDate = readData();
    cout << "Enter End Date:\n";   P1.EndDate = readData();

    cout << "\n------------------------------\n";

    cout << "Enter Period 2:\n";
    cout << "Enter Start Date:\n"; P2.StartDate = readData();
    cout << "Enter End Date:\n";   P2.EndDate = readData();

    cout << "------------------------------\n";

    if (Is_Overlap(P1, P2))
        cout << "Yes, Periods Overlap\n";
    else
        cout << "No, Periods do NOT Overlap\n";

    return 0;
}
