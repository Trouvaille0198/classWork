#include "CSolver.cpp"
//#include "CSolver.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    CSolver e1(2, -4, 2);
    e1.ShowEquation();
    e1.Solve();
    e1.ShowSolution();
    CSolver e2(1, -6, 2);
    e2.ShowEquation();
    e2.Solve();
    e2.ShowSolution();
    CSolver e3(2, 5, 8);
    e3.ShowEquation();
    e3.Solve();
    e3.ShowSolution();
    system("pause");
}