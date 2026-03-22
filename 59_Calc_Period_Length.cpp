#include <iostream>
using namespace std;


struct stDate {
    short year, month, day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};


bool check_If_Leap_Year(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Calc_Days_In_Month(short month, short year) {
    static short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2 && check_If_Leap_Year(year)) ? 29 : NumberOfDays[month - 1];
}

bool Check_Last_Day_In_Month(stDate date) {
    return (date.day == Calc_Days_In_Month(date.month, date.year));
}

bool Check_Last_Month_In_Year(stDate date) {
    return (date.month == 12);
}


void Increase_Date_by_One_Day(stDate &date) {
    if (Check_Last_Month_In_Year(date) && Check_Last_Day_In_Month(date)) {
        date.day = 1;
        date.month = 1;
        date.year++;
    }
    else if (Check_Last_Day_In_Month(date)) {
        date.day = 1;
        date.month++;
    }
    else {
        date.day++;
    }
}


short Is_Date1_After_Date2(stDate date1, stDate date2) {
    if (date1.year > date2.year) return 1;
    if (date1.year < date2.year) return -1;
    if (date1.month > date2.month) return 1;
    if (date1.month < date2.month) return -1;
    if (date1.day > date2.day) return 1;
    if (date1.day < date2.day) return -1;
    return 0;
}


short Calc_Period_Length(stPeriod Period, bool IncludedEndDay = false) {
    short Length = 0;
    while (Is_Date1_After_Date2(Period.StartDate, Period.EndDate) == -1) {
        Length++;
        Increase_Date_by_One_Day(Period.StartDate);
    }
    return IncludedEndDay ? ++Length : Length;
}


stDate readData() {
    stDate date;
    cout << "Please enter a Day? "; cin >> date.day;
    cout << "Please enter a Month? "; cin >> date.month;
    cout << "Please enter a Year? "; cin >> date.year;
    return date;
}

int main() {
    stPeriod P1;

    cout << "Enter Period 1:\n";
    cout << "Enter Start Date:\n";
    P1.StartDate = readData();
    cout << "Enter End Date:\n";
    P1.EndDate = readData();

    cout << "\n------------------------------\n";


    cout << "Period Length is: " << Calc_Period_Length(P1) << endl;

    cout << "------------------------------\n";

    cout << "Period Length (Included End Day) is: " << Calc_Period_Length(P1, true) << endl;

    return 0;
}
