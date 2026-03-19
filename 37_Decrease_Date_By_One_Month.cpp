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


bool Check_First_Month_In_Year(stDate & date)
{
    return (date.month == 1);
}

stDate Decrease_Date_By_One_day(stDate  date)
{
    if(date.day > 1)
        {
            date.day -= 1;
        }
    else if(date.day == 1)
        {
            if(Check_First_Month_In_Year(date))
                {
                    date.day = 31;
                    date.year -= 1;
                    date.month = 12;
                }
            else if(date.month >  1)
                {
                    date.month -= 1;
                    date.day = Calc_Days_In_Month(date.month,date.year);
                }
        }

    return date;
}

stDate Decrease_Date_By_One_Month(stDate  date)
{
    if(Check_First_Month_In_Year(date))
        {
            date.month = 12;
            date.year -= 1;
        }
    else
        {
            date.month -= 1;
        }
    short DaysInCurrentMonth = Calc_Days_In_Month(date.month,date.year);
    if(date.day > DaysInCurrentMonth)
        {
            date.day =  DaysInCurrentMonth;
        }

    return date;
}

int main()
{
    stDate date, Date_After_Subtracting;

    cout<<"enter date: \n";
    date = readData();
    cout<<"\nDate of year: "<<date.year<<"/"<<date.month<<"/"<<date.day<<endl;

    cout<<"------------------------------\n";

    cout<<"Subtracting date by one month\n";

    Date_After_Subtracting = Decrease_Date_By_One_Month(date);

    cout<<"Date After Subtracting\n";
    cout<<"\nDate of year: "<<Date_After_Subtracting.year<<"/"<<Date_After_Subtracting.month<<"/"<<Date_After_Subtracting.day<<endl;
    return 0;
}
