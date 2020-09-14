#include <bits/stdc++.h>
using namespace std;

int daysOfMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

char *NextDay(int year, int month, int day)
{
    static char result[50];
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

    char str1[10], str2[10], str3[10];
    itoa(year, str1, 10);
    itoa(month, str2, 10);
    itoa(day, str3, 10);
    strcat(result, str1);
    strcat(result, "/");
    strcat(result, str2);
    strcat(result, "/");
    strcat(result, str3);
    return result;
}
int main()
{
    /* char result[50];
    strcpy(result, *NextDay(2020, 9, 14)); */
    cout << NextDay(2020, 2, 29) << endl;
    system("pause");
}
