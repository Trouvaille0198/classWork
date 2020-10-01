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

void DeleteFirst(Dot *&head)
{
    Dot *p = new Dot;
    if (head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        delete p;
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

void SearchList(Dot *&head, int x)
{
    int flag = 0;
    Dot *p = new Dot;
    p = head->next;
    while (p != NULL)
    {
        if (p->point.Showm_x() == x)
        {
            cout << "The point you are searching is ("
                 << p->point.Showm_x() << ", "
                 << p->point.Showm_y() << "). " << endl;
            flag = 1;
        }
        p = p->next;
    }
    if (flag == 0)
    {
        cout << "Sorry, the point you are searching for does not exist. " << endl;
    }
}

Point p1(1, 1);

int main()
{

    Point p2(2, 2);
    Point pArray[3] = {Point(4, 4), Point(5, 5), Point(6, 6)};
    Point *p = new Point(3, 3);

    Dot *head = new Dot;
    head->next = NULL;
    InsertFirst(head, p1);
    InsertFirst(head, p2);
    InsertFirst(head, *p);
    for (int i = 0; i < 3; i++)
    {
        InsertFirst(head, pArray[i]);
    }
    DeleteFirst(head);
    DisplayList(head);
    SearchList(head, 5);
    system("pause");
}