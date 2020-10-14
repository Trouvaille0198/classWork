#ifndef LinkList_H
#define LinkList_H
#include <bits/stdc++.h>
using namespace std;

class Link
{
public:
    Link(int num, string name, int age, int grade); //构造函数
    Link(const Link &a);                            //拷贝构造函数
    Link &operator=(const Link &a);                 //赋值运算符函数
    ~Link();                                        //析构函数
    static void Show();                             //显示全部链表的各结点的学生信息
    static void ShowGrade(int flag);                //找出语文成绩最高/低的同学
    static void ShowAge(int age);                   //找出年龄为某岁的学生个数，并输出学生信息
    void DeleteNode();                              //删除指定节点
    static void SortByNumber();                     //按学号排序
    void ModifyGrade(int grade);                    //修改分数
    friend void ShowInfo(Link a);                   //显示某对象的全部信息

private:
    int m_number;
    string m_name;
    int m_age;
    int m_grade;
    Link *next;
    static Link *head;
    static int num;
};

Link *Link::head = NULL;
int Link::num = 0;

Link::Link(int number, string name, int age, int grade)
{
    num++;
    m_number = number;
    m_name = name;
    m_age = age;
    m_grade = grade;

    this->next = head;
    head = this;
    cout << "Create an object " << name << endl;
}

Link::Link(const Link &a)
{
    num++;
    m_number = a.m_number;
    m_name = a.m_name;
    m_age = a.m_age;
    m_grade = a.m_grade;

    this->next = head;
    head = this;
    cout << "Copy an object " << a.m_name << endl;
}

Link &Link::operator=(const Link &a)
{
    cout << "change " << m_name << "into " << a.m_name << endl;
    m_number = a.m_number;
    m_name = a.m_name;
    m_age = a.m_age;
    m_grade = a.m_grade;

    return *this;
}

Link::~Link()
{
    Link *pGuard = head;
    if (head == this)
        head = this->next;
    else
    {
        while (pGuard->next != this)
            pGuard = pGuard->next;
        pGuard->next = this->next;
    }
    num--;
    cout << "Delete the list successfully~" << endl;
}

void Link::Show()
{
    Link *p;
    cout << "Number of nodes: " << num << endl;
    for (p = head; p != NULL; p = p->next)
    {
        cout << "00" << p->m_number << setw(8) << p->m_name << setw(8) << p->m_age << "岁" << setw(8) << p->m_grade << "分" << endl;
    }
}

void Link::ShowGrade(int flag)
{
    Link *p;
    Link *HighGra, *LowGra;
    HighGra = head;
    LowGra = head;
    for (p = head; p != NULL; p = p->next)
    {
        if (p->m_grade > HighGra->m_grade)
        {
            HighGra = p;
        }
        if (p->m_grade < LowGra->m_grade)
        {
            LowGra = p;
        }
    }
    if (flag == 1)
        cout << HighGra->m_name << " gets the highest Chinese grade." << endl;
    else
        cout << LowGra->m_name << " gets the lowest Chinese grade." << endl;
}

void Link::ShowAge(int age)
{
    int count = 0;
    Link *p;
    cout << "Students in " << age << " years old: ";
    for (p = head; p != NULL; p = p->next)
    {
        if (p->m_age == age)
        {
            count++;
            cout << p->m_name << " ";
        }
    }
    cout << endl
         << count << " total students." << endl;
}

void Link::DeleteNode()
{
    Link *p;
    if (this == head)
    {
        head = this->next;
    }
    else
    {
        for (p = head; p != NULL; p = p->next)
        {
            if (p->next == this)
            {
                p->next = this->next;
                break;
            }
        }
    }
    num--;
    cout << this->m_name << " has deleted." << endl;
}

void Link::SortByNumber()
{
    Link *newHead = NULL, *p, *q, *max;
    int storedNum = num;
    while (num != 0)
    {

        for (q = max = head; q != NULL; q = q->next)
        {

            if (max->m_number < q->m_number)
            {
                max = q;
            }
        }
        for (q = head; q != NULL; q = q->next)
        {
            if (q == max)
            {
                if (q == head)
                {
                    head = q->next;
                }
                else
                {
                    for (p = head; p != NULL; p = p->next)
                    {
                        if (p->next == q)
                        {
                            p->next = q->next;
                            break;
                        }
                    }
                }
                num--;
            }
        }
        max->next = newHead;
        newHead = max;
    }
    head = newHead;
    num = storedNum;
    cout << "Finish sorting." << endl;
}

void Link::ModifyGrade(int grade)
{
    this->m_grade = grade;
    cout << this->m_name << "'s grade has changed into " << grade << endl;
}

void ShowInfo(Link a)
{
    cout << "00" << a.m_number << "  " << a.m_name
         << "  " << a.m_age << "岁 " << a.m_grade << "分" << endl;
}

#endif