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

void InsertFirst(Dot *&head)
{
    Dot *p;
    p = new Dot;
    p->point.Set();

    if (head->next == NULL)
        head->next = p;
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

int main()
{
    Dot *head;
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
    system("pause");
}