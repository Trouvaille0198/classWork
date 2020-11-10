#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    Student() {}
    Student(const Student &a) {}
    Student(int m_number) {} //转换构造函数
    virtual ~Student() {}
    Student &operator==(const Student &a) {}
    /*IO流操作运算符重载*/
    friend istream &operator>>(istream &in, Student &a);
    friend ostream &operator<<(ostream &out, Student &a);

private:
    string m_name;
    int m_number;
};

istream &operator>>(istream &in, Student &a) {}
ostream &operator<<(ostream &out, Student &a) {}

class AutoLink
{
public:
    AutoLink(const Student &data) {}          //构造函数
    AutoLink(const AutoLink &a) {}            //拷贝构造函数
    AutoLink &operator=(const AutoLink &a) {} //赋值运算符函数
    virtual ~AutoLink() {}                    //虚函数
    static void ShowLink() {}                 //显示所有节点信息

private:
    Student data;
    AutoLink *next;
    static AutoLink *head;
    static int num;
};

AutoLink AutoLink::*head = NULL;
int AutoLink::num = 0;

int main()
{
    /*write*/
    ofstream outfile;
    outfile.open("result.txt");
    outfile.close();
    /*read*/
    ifstream infile;
    infile.open("my_student.txt");
    infile.close();
}