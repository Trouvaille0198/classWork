#ifndef LinkList_H
#define LinkList_H
#include <bits/stdc++.h>
using namespace std;

class Link
{
public:
    Link(int num, string name, int age, int grade);
    Link(const Link &a);
    Link &operator=(const Link &a);
    ~Link();
    static void Show();
    static void ShowGrade(int flag);

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
    cout << "ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½" << m_name << endl;
}

void Link::Show()
{
    Link *p;
    cout << "Number of nodes: " << num << endl;
    for (p = head; p != NULL; p = p->next)
    {
        cout << "00" << p->m_number << "  " << p->m_name << "  " << p->m_age << "Ëê " << p->m_grade << "·Ö" << endl;
    }
}

void Link::ShowGrade(int flag)
{
    Link *p;
    Link *HighGra, *LowGra;
    HighGra = head;
    LowGra = head;
    for (p = head; p->next != NULL; p = p->next)
    {
        if (p->next->m_grade > HighGra->m_grade)
        {
            HighGra = p->next;
        }
        if (p->next->m_grade < LowGra->m_grade)
        {
            LowGra = p->next;
        }
    }
    if (flag == 1)
        cout << "³É¼¨×î¸ßµÄÊÇ£º" << HighGra->m_name << endl;
    else
        cout << "³É¼¨×îµÍµÄÊÇ£º" << LowGra->m_name << endl;
}
#endif