#include <bits/stdc++.h>
#include "Date.h"
#include "Date.cpp"
using namespace std;

int main()
{
    Date date1(2020, 9, 21);
    date1.Show();
    date1.SetDate(1997, 5, 6);
    date1.Show();
    date1.NextDay();
    date1.Show();
    system("pause");
}