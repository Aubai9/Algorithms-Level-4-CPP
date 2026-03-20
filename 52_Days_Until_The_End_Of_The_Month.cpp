#include <iostream>
#include <string>

using namespace std;

struct stDate
{
    short year;
    short month;
    short day;
};

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

short readDay()
{
    short day;
    cout<<"enter the day\n";
    cin>> day;
    return day;
}

short DayOfWeekOrder(short d, short m,short y)
{
    if (m == 1 || m == 2 )
        {
            m += 12;
            y -= 1;
        }

    int k = y % 100;
    int j = y / 100;
    int h = (d + ((13 *(m + 1))/5)+ k + (k/4) + (j/4) - 2 * j) % 7;

    if(h < 0) h+=7;

    return (h + 6) % 7;
}

short DayOfWeekOrder(stDate date)
{
    return DayOfWeekOrder(date.day, date.month, date.year);
}

string Print_Day(short & Zeller_Algorithm_Result)
{
    switch(Zeller_Algorithm_Result)
        {
        case 0 :
            return"Saturday";
            break;
        case 1 :
            return"Sunday";
            break;
        case 2:
            return"Monday";
            break;
        case 3:
            return"Tuesday";
            break;
        case 4:
            return"Wednesday";
            break;
        case 5:
            return"Thursday";
            break;
        case 6:
            return"Friday";
            break;
        default:
            cout<<"InValid input";
        }

}

int Calc_Days_In_Month(short month, short year)
{
    static short NumberOfDays[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    short index = month - 1;

    return (month == 2 && check_If_Leap_Year(year)) ?  29 :  NumberOfDays[index];
}


short Days_Until_The_End_Of_The_Month(stDate  date)
{
    short DaysInMonth = Calc_Days_In_Month(date.month,date.year);
    return (DaysInMonth - date.day);
}


int main()
{
    stDate date;
    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();

    short Zeller_Algorithm_Result =  DayOfWeekOrder(date.day, date.month,date.year);

    string Day = Print_Day(Zeller_Algorithm_Result);

    cout<<"Today is: "<<Day<<endl;

    (Days_Until_The_End_Of_The_Month(date) == 0) ? cout<<"Today is the end of the Month\n" : cout<<"Days until end of Month: "<<Days_Until_The_End_Of_The_Month(date);

    return 0;
}
