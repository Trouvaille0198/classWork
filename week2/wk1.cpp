#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
    double deltaX = x2 - x1;
    double deltaY = y2 - y1;
    double result;
    result = pow(deltaX, 2.0) + pow(deltaY, 2.0);
    result = pow(result, 0.5);
    return result;
}
int main()
{
    double a = distance(1.0,1.0,2.0,2.0);
    cout<<a<<endl;
    system("pause");
}
