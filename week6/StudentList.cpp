#include <bits/stdc++.h>
#include "LinkList.h"
using namespace std;

int main()
{
    Link stu1(1, "����", 20, 100), stu3(3, "����", 21, 89), stu6(6, "����", 19, 96), stu2(2, "����", 20, 68), stu5(5, "���˧", 19, 90), stu4(4, "����", 23, 85);
    Link::Show();
    Link::ShowGrade(1);
    Link::ShowGrade(0);
    system("pause");
}