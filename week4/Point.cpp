#include "Point.h"
#include <bits/stdc++.h>
using namespace std;

Point::Point(int x, int y)
{
    this->m_x = new int(x);
    this->m_y = new int(y);
}

Point::Point(const Point &N)
{
    this->m_x = new int(*N.m_x);
    this->m_y = new int(*N.m_y);
}

Point &Point::operator=(const Point &N)
{
    if (&N != this)
    {
        if (m_x != NULL && m_y != NULL)
        {
            delete m_x;
            delete m_y;
        }
        this->m_x = new int(*N.m_x);
        this->m_y = new int(*N.m_y);
    }
    return *this;
}

Point::~Point()
{
    if (m_x != NULL)
    {
        delete m_x;
        delete m_y;
    }
}

void Point::Show() const
{
    cout << *m_x << ", " << *m_y << endl;
    /*  cout << "ahhhhhhhhhhhhhhhhhhh" << endl; */
}

void Point::Set()
{
    int x, y;
    cout << "input x and y: ";
    cin >> x >> y;
    delete m_x;
    delete m_y;
    this->m_x = new int(x);
    this->m_y = new int(y);
}
