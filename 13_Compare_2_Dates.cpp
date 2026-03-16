#include <iostream>
#include <string>

using namespace std;

struct stDate
{
    short year;
    short month;
    short day;
};

stDate readData(stDate date)
{
    cout << "Enter year: ";
    cin >> date.year;
    cout << "Enter month: ";
    cin >> date.month;
    cout << "Enter day: ";
    cin >> date.day;
    return date;
}

bool Compare_Dates(stDate & date1, stDate  & date2)
{
    return (date1.year < date2.year) || (date1.year == date2.year && date1.month < date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

int main()
{
    stDate date1,date2;

    cout<<"enter date1: \n";
    date1 = readData(date1);
    cout<<"\nDate of year1: "<<date1.year<<"/"<<date1.month<<"/"<<date1.day<<endl;

    cout<<"------------------------------\n";

    cout<<"enter date2: \n";
    date2 = readData(date2);
    cout<<"\nDate of year2: "<<date2.year<<"/"<<date2.month<<"/"<<date2.day<<endl;

    bool Comparing_Result = Compare_Dates(date1,date2);

    if(Comparing_Result)
        {
            cout<<"date 1 is first\n";
        }
    else
        {
            cout<<"date 2 is first\n";
        }
    return 0;
}
