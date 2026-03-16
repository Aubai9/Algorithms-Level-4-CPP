#include <iostream>
#include <string>

using namespace std;

struct stDate
{
    short year;
    short month;
    short day;
};

stDate readData(stDate date)
{
    cout << "Enter year: ";
    cin >> date.year;
    cout << "Enter month: ";
    cin >> date.month;
    cout << "Enter day: ";
    cin >> date.day;
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

bool Check_Last_Day_In_Month(stDate & date)
{
    return (date.day == Calc_Days_In_Month(date.month,date.year));
}

bool Check_Last_Month_In_Year(stDate & date)
{
    return (date.month == 12);
}

int main()
{
    stDate date;

    cout<<"enter date: \n";
    date = readData(date);
    cout<<"\nDate of year: "<<date.year<<"/"<<date.month<<"/"<<date.day<<endl;

    cout<<"------------------------------\n";

    bool Is_Last_Day_In_Month = Check_Last_Day_In_Month(date);

    if(Is_Last_Day_In_Month)
        {
            cout<<"YES, "<<date.day <<" is the last day in month "<<date.month<<" ,year "<<date.year<<endl;
        }
    else
        {
            cout<<"NO, "<<date.day <<" is Not the last day in month "<<date.month<<" ,year "<<date.year<<endl;
        }

    cout<<"\n--------------------------------\n";

    bool Is_Last_Month_In_Year = Check_Last_Month_In_Year(date);

    if(Is_Last_Month_In_Year)
        {
            cout<<"YES, "<<date.month <<" is the last month in year "<<date.year<<endl;
        }
    else
        {
            cout<<"NO, "<<date.month <<" is Not the last month in year "<<date.year<<endl;
        }
    return 0;
}
