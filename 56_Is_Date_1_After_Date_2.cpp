#include <iostream>
#include <string>

using namespace std;

struct stDate
{
    short year;
    short month;
    short day;
};

stDate readData()
{
    stDate date;
    cout << "Please enter a Day? ";
    cin >> date.day;
    cout << "Please enter a Month? ";
    cin >> date.month;
    cout << "Please enter a Year? ";
    cin >> date.year;
    return date;
}

bool Is_Date1_After_Date2(stDate date1,stDate date2)
{
    return (date1.year > date2.year) ? true : (date1.year == date2.year && date1.month > date2.month) ? true :(date1.year == date2.year && date1.month == date2.month && date1.day > date2.day) ? true : false;
}


int main()
{
    stDate date1, date2;

    cout<<"Enter Date 1: \n";

    date1 = readData();

    cout << "\n------------------------------\n";

    date2 = readData();

    cout << "------------------------------\n";

    bool Result = Is_Date1_After_Date2(date1,date2);

    (Result) ? cout<<"Date 1, After Date 2\n" : cout<<"Date 1 is NOT After Date 2\n";

    return 0;
}
