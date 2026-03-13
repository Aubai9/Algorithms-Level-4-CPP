#include <iostream>
#include <string>

using namespace std;

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


int Calc_Days_In_Month(short month, short year)
{
    static short NumberOfDays[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

    short index = month - 1;

    return (month == 2 && check_If_Leap_Year(year)) ?  29 :  NumberOfDays[index];
}

short Zeller_Algorithm(short d, short m,short y)
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

int main()
{
    short day = readDay();
    short month = readMonth();
    short year = readYear();


    int DaysInMonth  = Calc_Days_In_Month(month, year);

    short Zeller_Algorithm_Result =  Zeller_Algorithm(DaysInMonth, month,year);

    switch(Zeller_Algorithm_Result)
        {
        case 0 :
            cout<<"Saturday";
            break;
        case 1 :
            cout<<"Sunday";
            break;
        case 2:
            cout<<"Monday";
            break;
        case 3:
            cout<<"Tuesday";
            break;
        case 4:
            cout<<"Wednesday";
            break;
        case 5:
            cout<<"Thursday";
            break;
        case 6:
            cout<<"Friday";
            break;
        default:
            cout<<"InValid input";
        }

    return 0;
}
