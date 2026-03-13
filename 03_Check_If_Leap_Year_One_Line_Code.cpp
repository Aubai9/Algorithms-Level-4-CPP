#include <iostream>
#include <string>

using namespace std;

bool check_If_Leap_Year(short year)
{
    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    short year;
    cout<<"enter the year to check if it Leap year\n";
    cin>> year;
    bool Leap_year = check_If_Leap_Year(year);
    if(Leap_year)
        {
            cout<<"Year:"<<year <<" ______ is leap\n";
        }
    else
        {
            cout<<"Year: "<<year <<" ______ is NOT leap\n";
        }
}
