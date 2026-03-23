#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct stDate {
    short year, month, day;
};


bool check_If_Leap_Year(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Calc_Days_In_Month(short month, short year) {
    static short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2 && check_If_Leap_Year(year)) ? 29 : NumberOfDays[month - 1];
}

bool Is_Valid_Date(stDate date) {
    if (date.month < 1 || date.month > 12) return false;
    if (date.year <= 0) return false;
    if (date.day < 1 || date.day > Calc_Days_In_Month(date.month, date.year)) return false;
    return true;
}


string ReplaceWordInString(string s, string wordToReplace, string sReplaceBy) {
    size_t pos = s.find(wordToReplace);
    while (pos != std::string::npos) {
        s.replace(pos, wordToReplace.length(), sReplaceBy);
        pos = s.find(wordToReplace);
    }
    return s;
}


string Format_Date(stDate date, string format = "dd/mm/yyyy") {
    string FormattedDateString = format;
    FormattedDateString = ReplaceWordInString(FormattedDateString, "dd", to_string(date.day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(date.month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(date.year));
    return FormattedDateString;
}


stDate readData() {
    stDate date;
    cout << "Please enter a Day? "; cin >> date.day;
    cout << "Please enter a Month? "; cin >> date.month;
    cout << "Please enter a Year? "; cin >> date.year;
    return date;
}

int main() {
    stDate date = readData();

    if (!Is_Valid_Date(date)) {
        cout << "\nInvalid Date!\n";
        return 0;
    }

    cout << "\n------------------------------\n";
    cout << "Different Formats for your date:\n\n";

   
    cout << Format_Date(date, "dd/mm/yyyy") << endl;
    cout << Format_Date(date, "yyyy/mm/dd") << endl;
    cout << Format_Date(date, "mm/dd/yyyy") << endl;
    cout << Format_Date(date, "dd-mm-yyyy") << endl;
    cout << Format_Date(date, "Day:dd, Month:mm, Year:yyyy") << endl;

    cout << "\n------------------------------\n";

    return 0;
}