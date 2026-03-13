#include <iostream>
#include <string>

using namespace std;


string numberToText(int number)
{
    static const string ones[] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string tens[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if (number == 0)
        {
            return "";
        }
    if(number < 20)
        {
            return ones[number] + " ";
        }
    if(number < 100)
        {
            return tens[number / 10] + " " + numberToText(number % 10);
        }
    if(number < 1000)
        {
            return ones[number / 100] + " Hundred " + numberToText(number % 100);
        }
    if(number < 1000000)
        {
            return numberToText(number / 1000) + " Thousand " + numberToText(number % 1000);
        }
    if(number < 1000000000)
        {
            return numberToText(number / 1000000) + " Million " + numberToText(number % 1000000);
        }
    return " number is too large!\n";
}

int main()
{
    int number;
    cout<<"enter your number\n";
    cin>> number;
    if(number == 0)
        {
            cout<<"Zero\n";
        }
    else
        cout<<numberToText(number);

}
