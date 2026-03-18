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

stDate Increase_Date_by_One_Week(stDate  date)
{
    for(short i = 1; i<= 7; i++)
        {
            date = Increase_Date_by_One_Day(date);
        }
    return date;
}

int main()
{
    stDate date, Date_After_Addition;

    cout<<"enter date: \n";
    date = readData();
    cout<<"\nDate of year: "<<date.year<<"/"<<date.month<<"/"<<date.day<<endl;

    cout<<"------------------------------\n";


    cout<<"Increase date by one week\n";

    Date_After_Addition =  Increase_Date_by_One_Week(date);

    cout<<"Date After Addition\n";
    cout<<"\nDate of year: "<<Date_After_Addition.year<<"/"<<Date_After_Addition.month<<"/"<<Date_After_Addition.day<<endl;
    return 0;
}
