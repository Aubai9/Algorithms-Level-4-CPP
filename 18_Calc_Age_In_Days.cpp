#include <iostream>
#include <string>
#include<ctime>

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

stDate Increase_Date_by_One_Day(stDate  date)
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

bool Is_Date1_Before_Date2(stDate & date1, stDate  & date2)
{
    return (date1.year < date2.year) || (date1.year == date2.year && date1.month < date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

void Swap_Dates(stDate & date1,stDate & date2)
{
    stDate tempDate;
    tempDate = date1;
    date1 = date2;
    date2 = tempDate;
}

int Get_Difference_In_Days(stDate date1,stDate  date2,bool IncludeLastDay = false)
{

    int Days = 0;
    if(!Is_Date1_Before_Date2(date1,date2))
        {
            Swap_Dates(date1,date2);
        }
    while(Is_Date1_Before_Date2(date1,date2))
        {
            Days++;
            date1 = Increase_Date_by_One_Day(date1);
        }
    return IncludeLastDay ? ++Days : Days ;
}

stDate GetSystemDate()
{
    stDate date;
    time_t t = time(0);
    tm* now = localtime(&t);
    date.year = now-> tm_year + 1900;
    date.month = now-> tm_mon + 1;
    date.day = now-> tm_mday;
    return date;
}


int main()
{
    stDate date1,date2, Date_After_Addition;

    cout<<"enter date 1: \n";
    date1 = readData();
    cout<<"\nDate of year1: "<<date1.year<<"/"<<date1.month<<"/"<<date1.day<<endl;

    cout<<"------------------------------\n";

    cout<<"Get current date: \n";
    date2 = GetSystemDate();
    cout<<"\nDate of year2: "<<date2.year<<"/"<<date2.month<<"/"<<date2.day<<endl;

    cout<<"\n------------------------------\n";

    cout<<"\nThe difference between dates:(NOT Include Last Day) "<<Get_Difference_In_Days(date1,date2)<<endl;
    cout<<endl;
    cout<<"\nThe difference between dates:(Include Last Day) "<<Get_Difference_In_Days(date1,date2,true)<<endl;

    cout<<"\n------------------------------\n";


    return 0;
}
