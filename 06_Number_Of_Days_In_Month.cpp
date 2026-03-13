#include <iostream>
#include <string>

using namespace std;

bool check_If_Leap_Year(short year)
{
    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short readYear()
{
    short year;
    cout<<"enter the year \n";
    cin>> year;
    return year;
}

short readMonth()
{
    short month;
    cout<<"enter the month\n";
    cin>> month;
    return month;
}

int Calc_Days_In_Month(short month, short year)
{
    static short NumberOfDays[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    short index = month - 1;

    return (month == 2 && check_If_Leap_Year(year)) ?  29 :  NumberOfDays[index];
}


int main()
{

    short year = readYear();
    short month = readMonth();

    int DaysInMonth  = Calc_Days_In_Month(month, year);

    cout<<"Days in  Month " << Calc_Days_In_Month(month,year)<<endl;

}
