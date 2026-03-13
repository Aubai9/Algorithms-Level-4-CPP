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
    cout<<"enter the year \n";
    cin>> year;
    int days  = (check_If_Leap_Year(year)) ? 366 : 365;
    int hours = days * 24;
    int minutes = days * 24 * 60;
    int seconds = days * 24 * 60 *60;
    bool Leap_year = check_If_Leap_Year(year);
    if(Leap_year)
        {
            cout<<"Days in Leap year " << days<<endl;
            cout<<"Hours in Leap year " << hours<<endl;
            cout<<"Minutes in Leap year " << minutes<<endl;
            cout<<"Seconds in Leap year " << seconds<<endl;
        }
    else
        {
            cout<<"Days in  year " << days<<endl;
            cout<<"Hours in  year " << hours<<endl;
            cout<<"Minutes in  year " << minutes<<endl;
            cout<<"Seconds in  year " << seconds<<endl;
        }
}
