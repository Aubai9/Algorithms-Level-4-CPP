#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct stDate
{
    short year;
    short month;
    short day;
};

// æÙíİÉ ááÊÍŞŞ ãä ÇáÓäÉ ÇáßÈíÓÉ
bool check_If_Leap_Year(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// æÙíİÉ áÍÓÇÈ ÚÏÏ ÃíÇã ÇáÔåÑ
int Calc_Days_In_Month(short month, short year)
{
    static short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2 && check_If_Leap_Year(year)) ? 29 : NumberOfDays[month - 1];
}

// æÙíİÉ ááÊÍŞŞ ãä ÂÎÑ íæã İí ÇáÔåÑ
bool Check_Last_Day_In_Month(stDate date)
{
    return (date.day == Calc_Days_In_Month(date.month, date.year));
}

// æÙíİÉ ááÊÍŞŞ ãä ÂÎÑ ÔåÑ İí ÇáÓäÉ
bool Check_Last_Month_In_Year(stDate date)
{
    return (date.month == 12);
}

// æÙíİÉ áÒíÇÏÉ ÇáÊÇÑíÎ íæãÇğ æÇÍÏÇğ
stDate Increase_Date_by_One_Day(stDate date)
{
    if (Check_Last_Month_In_Year(date) && Check_Last_Day_In_Month(date))
    {
        date.day = 1;
        date.month = 1;
        date.year += 1;
    }
    else if (Check_Last_Day_In_Month(date))
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

// æÙíİÉ ááÊÍŞŞ ÅĞÇ ßÇä ÇáÊÇÑíÎ ÇáÃæá ŞÈá ÇáËÇäí
bool Is_Date1_Before_Date2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ||
           (date1.year == date2.year && date1.month < date2.month) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

// æÙíİÉ áÊÈÏíá ÇáÊæÇÑíÎ
void Swap_Dates(stDate& date1, stDate& date2)
{
    stDate tempDate = date1;
    date1 = date2;
    date2 = tempDate;
}

// æÙíİÉ áÍÓÇÈ ÇáİÑŞ ÈÇáÃíÇã Èíä ÊÇÑíÎíä
int Get_Difference_In_Days(stDate date1, stDate date2, bool IncludeLastDay = false)
{
    int Days = 0;
    if (!Is_Date1_Before_Date2(date1, date2))
    {
        Swap_Dates(date1, date2);
    }
    while (Is_Date1_Before_Date2(date1, date2))
    {
        Days++;
        date1 = Increase_Date_by_One_Day(date1);
    }
    return IncludeLastDay ? ++Days : Days;
}

// æÙíİÉ áÌáÈ ÊÇÑíÎ Çáíæã ãä ÇáäÙÇã
stDate GetSystemDate()
{
    stDate date;
    time_t t = time(0);
    tm* now = localtime(&t);
    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;
    return date;
}

// ÇáæÙíİÉ ÇáãØáæÈÉ: ÍÓÇÈ ÇáÚãÑ ÈÇáÃíÇã
int Calc_Age_In_Days(stDate DateOfBirth, bool IncludeLastDay = false)
{
    return Get_Difference_In_Days(DateOfBirth, GetSystemDate(), IncludeLastDay);
}

// æÙíİÉ áŞÑÇÁÉ ÇáÊÇÑíÎ ãä ÇáãÓÊÎÏã
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

int main()
{
    cout << "Please Enter Your Date of Birth:\n";
    stDate DateOfBirth = readData();

    stDate SystemDate = GetSystemDate();
    cout << "\nToday is: " << SystemDate.year << "/" << SystemDate.month << "/" << SystemDate.day << endl;

    int AgeInDays = Calc_Age_In_Days(DateOfBirth, true);

    cout << "\nYour Age in Days is: " << AgeInDays << " Days." << endl;

    return 0;
}
