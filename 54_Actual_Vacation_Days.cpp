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
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short DayOfWeekOrder(stDate date)
{
    short a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + (12 * a) - 2;
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}


bool Is_WeekEnd(stDate date)
{
    short dayOrder = DayOfWeekOrder(date);
    return (dayOrder == 5 || dayOrder == 6);
}


bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);
}

int Calc_Days_In_Month(short month, short year)
{
    static short NumberOfDays[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    short index = month - 1;

    return (month == 2 && check_If_Leap_Year(year)) ?  29 :  NumberOfDays[index];
}


stDate IncreaseDateByOneDay(stDate Date)
{
    if (Date.day == Calc_Days_In_Month(Date.month, Date.year))
        {
            if (Date.month == 12)
                {
                    Date.month = 1;
                    Date.year++;
                }
            else
                {
                    Date.month++;
                }
            Date.day = 1;
        }
    else
        {
            Date.day++;
        }
    return Date;
}

short Actual_Vacation_Days(stDate DateFrom, stDate DateTo)
{
    short DaysCount = 0;
    while(IsDate1BeforeDate2(DateFrom,DateTo)){
        if(!Is_WeekEnd(DateFrom)){
            DaysCount++;
        }
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DaysCount;
}

int main()
{
    stDate StartDate,EndDate;

    cout<<"Vacation Starts:\n";
    StartDate = readData();

    cout<<"------------------------------\n";

    cout<<"Vacation Ends:\n";

    EndDate = readData();

    cout<<"------------------------------\n";

    cout<<"\nStarts of Vacation: "<<StartDate.year<<"/"<<  StartDate.month<<"/"<< StartDate.day<<endl;

    cout<<"\nEnds of Vacation: "<<   EndDate.year<<"/"<<  EndDate.month<<"/"<<  EndDate.day<<endl;

    cout<<"\nActual Vacation Days(Weekends are excluded):  "<<Actual_Vacation_Days(StartDate,EndDate)<<endl;

    cout<<"\n------------------------------\n";

    return 0;
}
