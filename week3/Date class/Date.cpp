#include <bits/stdc++.h>
#include "Date.h"
using namespace std;

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}
int Date::GetYear() const
{
    return year;
}
int Date::GetMonth() const
{
    return month;
}
int Date::GetDay() const
{
    return day;
}
void Date::Show() const
{
    cout << year << "/" << month << "/" << day << endl;
}
void Date::SetDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

const int daysOfMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int judgeLeapYear(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}

int getDays(int year, int month)
{
    if (judgeLeapYear(year) == 1 && month == 2)
        return 29;
    else
        return daysOfMonths[month - 1];
}

void Date::NextDay()
{
    day++;
    if (day > getDays(year, month))
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}
