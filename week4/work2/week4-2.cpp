
#include <iostream>
#include"Point.h"
using namespace std;
struct  PointList
{
    Point p;
    PointList* next;
};
void insertHead(PointList*& head,Point newp)
{
    PointList* q;
   q = (PointList*)malloc(sizeof(PointList));
    //PointList *q = new PointList;
    q->p = newp;
    if (head->next == NULL)//原先为空链表
    {
        head->next = q;
        q->next = NULL;
    }
    else
    {
        q->next = head->next;
        head->next = q;
    }
}//插入
void displayList(PointList*& head)
{
    PointList* q = head->next;
    while (q != NULL)
    {
        q->p.Show();
        q = q->next;
    }
}//显示
Point p1(1, 1);
int main()
{
    Point p2(2, 2);
    Point arrayp[3] = { Point(3,3), Point(4,4),Point(5,5) };
    Point* p = new Point(6, 6);
    PointList* head;
    head = (PointList*)malloc(sizeof(PointList));
    head->next = NULL;
    insertHead(head, p1);//插入全局量
    insertHead(head, p2);//插入局部量
    for (int i = 0; i < 3; i++)
    {
        insertHead(head, arrayp[i]);//插入数组
    }
    insertHead(head, *p);//插入指针
    displayList(head);
}

