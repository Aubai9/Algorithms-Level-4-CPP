#include <iostream>
#include <string>

using namespace std;

bool check_If_Leap_Year(short year)
{
    if(year % 4 == 0 && year % 100 != 0)
        {
            return true;
        }
    else if( year % 400 == 0)
        {
            return true;
        }
    else
        {
            return false;
        }
}

int main()
{
    short year;
    cout<<"enter the year to check if it Leap year\n";
    cin>> year;
    bool Leap_year = check_If_Leap_Year(year);
    if(Leap_year)
        {
            cout<<"Year: "<<year <<" is leap\n";
        }
    else
        {
            cout<<"Year: "<<year <<" is NOT leap\n";
        }
}
