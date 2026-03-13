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
    short  arr31Days[7] = {1,3,5,7,8,10,12};

    if(month == 2 && check_If_Leap_Year(year))
        {
            return 29;
        }
    for(short i = 1; i <= 7 ; i++)
        {
            if(month == arr31Days[i])
                {
                    return 31;
                }
        }
    return 30;
}
int Hours_In_month(short month,short year)
{
    return Calc_Days_In_Month(month,year) * 24;
}

int  Minutes_In_month(short month,short year)
{
    return Hours_In_month(month,year) * 60;
}

int Seconds_In_month(short month,short year)
{
    return Minutes_In_month(month,year) * 60;
}

int main()
{

    short year = readYear();
    short month = readMonth();
    int DaysInMonth  = Calc_Days_In_Month(month, year);

    cout<<"Days in  Month " << Calc_Days_In_Month(month,year)<<endl;
    cout<<"Hours in  Month " << Hours_In_month(month, year)<<endl;
    cout<<"Minutes in  Month " << Minutes_In_month(month, year)<<endl;
    cout<<"Seconds in  Month " << Seconds_In_month(month, year)<<endl;

}
