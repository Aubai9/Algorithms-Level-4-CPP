#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool check_If_Leap_Year(short year)
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

int Calc_Days_In_Month(short month, short year)
{
    static short NumberOfDays[12] =
    {31,28,31,30,31,30,31,31,30,31,30,31};

    short index = month - 1;

    if (month == 2 && check_If_Leap_Year(year))
        return 29;

    return NumberOfDays[index];
}

short Zeller_Algorithm(short d, short m, short y)
{
    if (m == 1 || m == 2)
    {
        m += 12;
        y -= 1;
    }

    int k = y % 100;
    int j = y / 100;

    int h = (d + ((13 * (m + 1)) / 5) + k + (k / 4) + (j / 4) - 2 * j) % 7;

    if (h < 0)
        h += 7;

    return (h + 6) % 7;
}

void Month_Calendar(short Month, short Year)
{
    int NumberOfDays = Calc_Days_In_Month(Month, Year);
    int current = Zeller_Algorithm(1, Month, Year);

    cout << "\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    int i;
    for (i = 0; i < current; i++)
        cout << "     ";

    for (int j = 1; j <= NumberOfDays; j++)
    {
        cout << setw(5) << j;

        if (++i == 7)
        {
            i = 0;
            cout << endl;
        }
    }

    cout << "\n-----------------------------------\n";
}

void Print_Year_Calendar(short year)
{
    for (short month = 1; month <= 12; month++)
    {
        Month_Calendar(month, year);
        cout << endl;
    }
}

int main()
{
    short year = readYear();

    cout << "\n========================\n";
    cout << "\n-------- " << year << " --------\n";
    cout << "\n========================\n";

    Print_Year_Calendar(year);

    return 0;
}
