#include <iostream>
#include<vector>
using namespace std;

struct stDate
{
    short year, month, day;
};


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

bool Is_Valid_Date(stDate & date)
{
    if( date.month < 1 || date.month > 12 )
        {
            return false;
        }
    if(date.day < 1 || date.day > Calc_Days_In_Month(date.month, date.year))
        {
            return false;
        }
    if(date.year <= 0)
        return false;
    return true;
}

vector <string> Split_String(string s, string Delim = "/")
{
    vector<string> vString;
    short pos = 0;
    string word;
    while((pos = s.find(Delim)!= std::string::npos))
        {
            word = s.substr(0,pos);

            if(word != "")
                {
                    vString.push_back(word);
                }
            s.erase(0,pos + Delim.length());
        }
    if(s!= "")
        {
            vString.push_back(s);
        }
    return vString;
}

stDate Convert_String_To_Structure(string DateString)
{
    stDate date;
    vector<string>  vDateData = Split_String(DateString,"/");
    date.day = stoi(vDateData[0]);
    date.month = stoi(vDateData[1]);
    date.year = stoi(vDateData[2]);
    return date;
}

int main()
{
    string StringDate;
    stDate date;

    cout<<"Enter your date dd/mm/yyyy\n";

    cin>> StringDate;

    cout << "\n------------------------------\n";

    date = Convert_String_To_Structure(StringDate);

    cout<<"Day: "<<date.day<<endl;
    cout<<"Month: "<<date.month<<endl;
    cout<<"Year: "<<date.year<<endl;

    cout<<"\nDate of year: "<<StringDate;

    cout << "\n------------------------------\n";

    return 0;
}
