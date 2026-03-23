#include <iostream>
using namespace std;

struct stDate
{
    short year, month, day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

bool Check_Last_Day_In_Month(stDate & date)
{
    return (date.day == Calc_Days_In_Month(date.month,date.year));
}

bool Check_Last_Month_In_Year(stDate & date)
{
    return (date.month == 12);
}

stDate Increase_Date_by_One_Day(stDate  & date)
{
    if(Check_Last_Month_In_Year(date) && Check_Last_Day_In_Month(date))
        {
            date.day = 1;
            date.month = 1;
            date.year += 1;
        }
    else if(Check_Last_Day_In_Month(date))
        {
            date.day = 1;
            date.month += 1;
        }
    else
        {
            date.day += 1;
        }

    return date;
}

short Compare_Dates(stDate date1, stDate date2)
{
    if (date1.year > date2.year) return 1;
    if (date1.year < date2.year) return -1;
    if (date1.month > date2.month) return 1;
    if (date1.month < date2.month) return -1;
    if (date1.day > date2.day) return 1;
    if (date1.day < date2.day) return -1;
    return 0;
}

bool Is_Date1_After_Date2(stDate date1,stDate date2)
{
    return (date1.year > date2.year) ? true : (date1.year == date2.year && date1.month > date2.month) ? true :(date1.year == date2.year && date1.month == date2.month && date1.day > date2.day) ? true : false;
}

bool Is_Overlap(stPeriod Period1, stPeriod Period2)
{
    if (Compare_Dates(Period1.EndDate, Period2.StartDate) == -1)
        return false;

    if (Compare_Dates(Period1.StartDate, Period2.EndDate) == 1)
        return false;

    return true;
}


int Count_Overlap_Days(stPeriod Period1, stPeriod Period2)
{
    if (!Is_Overlap(Period1, Period2))
        return 0;

    int OverlapDays = 0;


    stDate CurrentDate;
    if (Compare_Dates(Period1.StartDate, Period2.StartDate) == 1)
        CurrentDate = Period1.StartDate;
    else
        CurrentDate = Period2.StartDate;


    stDate EndDate;
    if (Compare_Dates(Period1.EndDate, Period2.EndDate) == -1)
        EndDate = Period1.EndDate;
    else
        EndDate = Period2.EndDate;

    while (Compare_Dates(CurrentDate, EndDate) <= 0)
        {
            OverlapDays++;
            Increase_Date_by_One_Day(CurrentDate);
        }

    return OverlapDays;
}


int main()
{
    stPeriod P1, P2;

    cout << "Enter Period 1:\n";
    cout << "Enter Start Date:\n";
    P1.StartDate = readData();
    cout << "Enter End Date:\n";
    P1.EndDate = readData();

    cout << "\n------------------------------\n";

    cout << "Enter Period 2:\n";
    cout << "Enter Start Date:\n";
    P2.StartDate = readData();
    cout << "Enter End Date:\n";
    P2.EndDate = readData();

    cout << "------------------------------\n";

    short counter = Count_Overlap_Days(P1,P2);

    cout<<"Overlap Days Count: "<<counter;

    return 0;
}
