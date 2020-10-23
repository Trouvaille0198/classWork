#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    int asw = Fibonacci(6);
    cout << asw << endl;
    getchar();
    getchar();
}