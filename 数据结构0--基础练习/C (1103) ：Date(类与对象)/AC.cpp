#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
class Date
{
    int year, month, day;
public:
    Date();
    Date(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);
    void print();
    void addOneDay();
};
Date::Date()
{
    this->year = 1900;
    this->month = 1;
    this->day = 1;
}
Date::Date(int y, int m, int d)
{
    this->year = y;
    this->month = m;
    this->day = d;
}
int Date::getYear()
{
    return this->year;
}
int Date::getMonth()
{
    return this->month;
}
int Date::getDay()
{
    return this->day;
}
void Date::setDate(int y, int m, int d)
{
    this->year = y;
    this->month = m;
    this->day = d;
}
void Date::print()
{
    cout << setfill('0') << setw(2) << this->year << '/'
        << setfill('0') << setw(2) << this->month << '/'
        << setfill('0') << setw(2) << this->day;
}
bool is_year(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year%400==0)
        return 1;
    return 0;
}
void Date::addOneDay()
{
    this->day++;
    if (this->day > 28 && !is_year(this->year) && this->month == 2)
        this->day -= 28, this->month++;
    if (this->day > 29 && is_year(this->year) && this->month == 2)
        this->day -= 29, this->month++;
    //4.6.8.9.11 30days
    if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
    {
        if (this->day > 30)
            this->day -= 30, this->month++;
    }
    else
    {
        if (this->day > 31)
            this->day -= 31, this->month++;
    }
    if (this->month > 12)
        this->month = 1, this->year++;
}
int main()
{
    int t, i, y, m, d;
    cin >> t;
    Date* p = new Date[t];
    for (i = 0; i < t; i++)
    {
        cin >> y >> m >> d;
        (p + i)->setDate(y, m, d);
        cout << "Today is ";
        (p + i)->print();
        cout << endl;
        cout << "Tomorrow is ";
        (p + i)->addOneDay();
        (p + i)->print();
        if (i != t - 1)
            cout << endl;
    }
    return 0;
}
/**********************************************************************
	Problem: 1103
	User: 202200201118
	Language: C++
	Result: AC
	Time:6 ms
	Memory:2220 kb
**********************************************************************/
