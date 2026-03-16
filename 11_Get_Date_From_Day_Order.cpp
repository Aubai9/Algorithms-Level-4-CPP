#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool Is_Leap_Year(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short readYear()
{
    short year;
    cout << "Enter the year:\n";
    cin >> year;
    return year;
}

short readMonth()
{
    short month;
    cout<<"enter the month:\n";
    cin>> month;
    return month;
}

short readDay()
{
    short day;
    cout<<"enter the day:\n";
    cin>> day;
    return day;
}

int Calc_Days_In_Month(short month, short year)
{
    static short NumberOfDays[12] =
    {31,28,31,30,31,30,31,31,30,31,30,31};

    short index = month - 1;

    if (month == 2 && Is_Leap_Year(year))
        return 29;

    return NumberOfDays[index];
}


int  NumberOfDaysFromBeginningOfTheYear(short month,short year,short day)
{
    int totalDays = 0;

    for(short i = 1; i <= month - 1; i++ )
        {
            totalDays += Calc_Days_In_Month(i,year);
        }
    totalDays += day;
    return totalDays;
}

void GetDateFromDayOrderInYear(short year)
{
    short Month_Number = 1;



    short Day_Order;
    cout<<"Enter the day order ";
    cin>>Day_Order;

    short Days_In_Current_Month = 0;

    while(true)
        {
            Days_In_Current_Month = Calc_Days_In_Month(Month_Number,year);
            if(Day_Order > Days_In_Current_Month)
                {
                    Day_Order -= Days_In_Current_Month;
                    Month_Number++;
                }
            else
                {
                    break;
                }
        }

    cout<<"Date is: "<<Day_Order<<"/"<<Month_Number<<"/"<<year<<endl;

}

int main()
{
    short year = readYear();
    short month = readMonth();
    short day = readDay();

    cout<<"The Date you entered: "<<day<<"/"<<month<<"/"<<year<<endl;

    int NumberOfDaysFromBeginning =  NumberOfDaysFromBeginningOfTheYear(month,year,day);
    cout<<"Total Days: "<<NumberOfDaysFromBeginning<<endl;

    GetDateFromDayOrderInYear(year);
    return 0;
}
