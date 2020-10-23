#include "LinkList.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Link stu1(1, "张三", 20, 100), stu3(3, "李四", 21, 89),
        stu6(6, "王五", 19, 96), stu2(2, "赵六", 20, 68),
        stu5(5, "马大帅", 19, 90), stu4(4, "孙七", 23, 85);

    Link::ShowGrade(1);
    Link::ShowGrade(0);
    Link::ShowAge(20);
    Link::Show();
    Link::SortByNumber();
    stu2.DeleteNode();
    stu6.ModifyGrade(97);
    ShowInfo(stu6);
    Link::Show();
    system("pause");
}