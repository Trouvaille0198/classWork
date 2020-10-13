#ifndef LinkList_H
#define LinkList_H
#include <bits/stdc++.h>
using namespace std;

class LinkList;

class Node
{
public:
    Node(int num, string name, int age, int grade);
    //Node(const Node &N);
    //Node &operator=(const Node &N);
    friend class LinkList;

private:
    int m_number;
    string m_name;
    int m_age;
    int m_grade;
    Node *next;
};

class LinkList
{
    Node *head, *curNode;
    int num;
};

#endif