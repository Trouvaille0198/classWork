#include "Point.cpp"
#include "Point.h"
#include <bits/stdc++.h>
using namespace std;

struct Dot
{
    Point point;
    Dot *next;
};

/* void insertLast(Dot *&head)
{
    Dot *p, *q;
    p = new Dot;
    cout << "输入参数一:";
    cin >> p->size;
    cout << "输入参数二:";
    cin >> p->amount;

    if (head->next == NULL)
        head->next = p;
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    p->next = NULL;
}
 */

/* void InsertFirst(Dot *&head)
{
    Dot *p;
    p = new Dot;
    p->point.Set();

    if (head->next == NULL)
    {
        head->next = p;
        p->next = NULL;
    }
    else
    {
        p->next = head->next;
        head->next = p;
    }
} */

void InsertFirst(Dot *&head, Point poi)
{
    Dot *p;
    p = new Dot;
    p->point = poi;
    if (head->next == NULL)
    {
        head->next = p;
        p->next = NULL;
    }
    else
    {
        p->next = head->next;
        head->next = p;
    }
}

void DisplayList(Dot *&head)
{
    Dot *p = head->next;
    while (p != NULL)
    {
        p->point.Show();
        p = p->next;
    }
}

Point p1(1, 1);

int main()
{
    /*   Dot *head;
    head = new Dot;
    head->next = NULL;
    cout << "1" << endl;
    InsertFirst(head);
    cout << "2" << endl;
    InsertFirst(head);
    cout << "3" << endl;
    InsertFirst(head);
    cout << "4" << endl;
    DisplayList(head);
    system("pause"); */

    Point p2(2, 2);
    Point pArray[3] = {Point(9, 9), Point(8, 8), Point(7, 7)};
    Point *p = new Point(3, 3);

    Dot *head = new Dot;
    head->next = NULL;
    InsertFirst(head, p1);
    InsertFirst(head, p2);
    for (int i = 0; i < 3; i++)
    {
        InsertFirst(head, pArray[i]);
    }
    InsertFirst(head, *p);
    DisplayList(head);
    system("pause");
}