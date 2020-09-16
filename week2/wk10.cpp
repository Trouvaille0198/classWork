#include <bits/stdc++.h>
using namespace std;

int Sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int a[10] = {12, 32, 42, 51, 8, 16, 51, 21, 19, 9};
    double b[10] = {32.1, 456.87, 332.67, 442.0, 98.12, 451.79, 340.12, 54.55, 99.87, 72.5};
    string c[10] = {"enter", "number", "size", "begin", "of", "cat", "case", "program", "certain", "a"};
    getchar();
    getchar();
}