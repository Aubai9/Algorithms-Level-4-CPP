#include <iostream>
#include <string>

using namespace std;

bool Is_Leap_Year(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


short Calc_Days_In_Month(short month, short year) {
    static short NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && Is_Leap_Year(year)) return 29;
    return NumberOfDays[month - 1];
}

void Add_Days_To_Date(short year, short month, short day) {
    int daysToAdd;
    cout << "Enter number of days you want to add: ";
    cin >> daysToAdd;

    int totalDays = daysToAdd + day;
    int remainingDays = day + daysToAdd;

    while (true) {
        short daysInCurrentMonth = Calc_Days_In_Month(month, year);

        if (remainingDays > daysInCurrentMonth) {
            remainingDays -= daysInCurrentMonth;
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        } else {

            day = (short)remainingDays;
            break;
        }
    }

    cout << "\nNew Date is: " << day << "/" << month << "/" << year << endl;
}

int main() {
    short year, month, day;

    cout << "Enter year: "; cin >> year;
    cout << "Enter month: "; cin >> month;
    cout << "Enter day: "; cin >> day;

    cout << "\nThe Date you entered: " << day << "/" << month << "/" << year << endl;

    Add_Days_To_Date(year, month, day);

    return 0;
}
