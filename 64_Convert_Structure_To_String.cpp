#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct stDate
{
    short year, month, day;
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

bool check_If_Leap_Year(short year)
{
    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Calc_Days_In_Month(short month, short year)
{
    static short NumberOfDays[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    short index = month - 1;

    return (month == 2 && check_If_Leap_Year(year)) ?  29 :  NumberOfDays[index];
}

bool Is_Valid_Date(stDate & date)
{
    if( date.month < 1 || date.month > 12 )
        {
            return false;
        }
    if(date.day < 1 || date.day > Calc_Days_In_Month(date.month, date.year))
        {
            return false;
        }
    if(date.year <= 0)
        return false;
    return true;
}


string Convert_Structure_To_String(stDate date, string Delim = "/")
{
    string sDate = "";
    sDate += to_string(date.day) + Delim;
    sDate += to_string(date.month) + Delim;
    sDate += to_string(date.year);
    return sDate;
}

int main()
{
    string StringDate;
    stDate date;

    cout<<"Enter your date\n";

    date = readData();

    cout<<"\nDate of year: "<<date.year<<"/"<<date.month<<"/"<<date.day<<endl;

    cout << "\n------------------------------\n";

    StringDate = Convert_Structure_To_String(date);

    cout<<"\nDate of year:(String) "<<StringDate;

    return 0;
}
