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

private:
    int m_number;
    string m_name;
    int m_age;
    int m_grade;
    Link *next;
    static Link *head;
    static int num;
};

Link::Link(int num, string name, int age, int grade)
{
    num++;
    m_number = num;
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
        head = next;
    else
    {
        while (pGuard->next != this)
            pGuard = pGuard->next;
        pGuard->next = next;
    }
    num--;
    cout << "析构一个对象" << m_name << endl;
}

#endif