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
    cout << "Please enter a Day? ";
    cin >> date.day;
    cout << "Please enter a Month? ";
    cin >> date.month;
    cout << "Please enter a Year? ";
    cin >> date.year;
    return date;
}

short Is_Date1_After_Date2(stDate date1,stDate date2)
{
    if(date1.year > date2.year)
        {
            return 1;
        }
    if(date1.year < date2.year)
        {
            return -1;
        }
    if(date1.month > date2.month)
        {
            return 1;
        }
    if(date1.month < date2.month)
        {
            return -1;
        }
    if(date1.day > date2.day)
        {
            return 1;
        }
    if(date1.day < date2.day)
        {
            return -1;
        }
    return 0;
}


int main()
{
    stDate date1, date2;

    cout<<"Enter Date 1: \n";

    date1 = readData();

    cout << "\n------------------------------\n";

    date2 = readData();

    cout << "------------------------------\n";

    int Result = Is_Date1_After_Date2(date1,date2);

    if(Result == 1)
        cout<<"Compare Result = "<<Result  ;
    if(Result == 0)
        cout<<"Compare Result = "<<Result  ;
    if(Result == -1)
        cout<<"Compare Result = "<<Result  ;
    return 0;
}
