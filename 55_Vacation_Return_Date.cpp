#include <iostream>
#include <string>

using namespace std;

struct stDate {
    short year;
    short month;
    short day;
};


bool check_If_Leap_Year(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Calc_Days_In_Month(short month, short year) {
    static short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2 && check_If_Leap_Year(year)) ? 29 : NumberOfDays[month - 1];
}

short DayOfWeekOrder(stDate date) {
    short a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + (12 * a) - 2;
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetDayName(short DayOrder) {
    string Days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    return (DayOrder >= 0 && DayOrder <= 6) ? Days[DayOrder] : "Invalid";
}


bool Is_WeekEnd(stDate date) {
    short dayOrder = DayOfWeekOrder(date);
    return (dayOrder == 5 || dayOrder == 6);
}

bool Is_BusinessDay(stDate date) {
    return !Is_WeekEnd(date);
}

stDate IncreaseDateByOneDay(stDate Date) {
    if (Date.day == Calc_Days_In_Month(Date.month, Date.year)) {
        if (Date.month == 12) {
            Date.month = 1;
            Date.year++;
        } else {
            Date.month++;
        }
        Date.day = 1;
    } else {
        Date.day++;
    }
    return Date;
}


stDate CalculateReturnDate(stDate date, short VacationDays) {
    short Counter = 0;


    while (Counter < VacationDays) {
        if (Is_BusinessDay(date)) {
            Counter++;
        }


        if (Counter == VacationDays) {
            break;
        }

        date = IncreaseDateByOneDay(date);
    }


    date = IncreaseDateByOneDay(date);


    while (Is_WeekEnd(date)) {
        date = IncreaseDateByOneDay(date);
    }

    return date;
}

stDate readData() {
    stDate date;
    cout << "Please enter a Day? "; cin >> date.day;
    cout << "Please enter a Month? "; cin >> date.month;
    cout << "Please enter a Year? "; cin >> date.year;
    return date;
}

int main() {
    stDate StartDate, EndDate;
    short VacationDays;

    cout << "Vacation Starts:\n";
    StartDate = readData();

    cout << "\nEnter Vacation Days: ";
    cin >> VacationDays;

    EndDate = CalculateReturnDate(StartDate, VacationDays);

    cout << "\n------------------------------\n";
    cout << "Vacation From: " << GetDayName(DayOfWeekOrder(StartDate)) << " , " << StartDate.day << "/" << StartDate.month << "/" << StartDate.year << endl;
    cout << "Return Date:   " << GetDayName(DayOfWeekOrder(EndDate)) << " , " << EndDate.day << "/" << EndDate.month << "/" << EndDate.year << endl;
    cout << "------------------------------\n";

    return 0;
}
