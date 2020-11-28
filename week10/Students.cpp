#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    Student(string id = "000", string name = "default name", int lang = 60, int math = 60)
        : m_id(id), m_name(name), m_lang(lang), m_math(math) {}
    //Student(const Student &a) {}
    //Student(string id) {} //转换构造函数
    //virtual ~Student() {}
    //Student &operator=(const Student &a) {}
    /*获取学生信息函数组*/
    int TotalGrade() const
    {
        int total;
        total = m_lang + m_math;
        return total;
    }
    double AverageGrade() const
    {
        double average;
        average = (m_lang + m_math) / 2;
        return average;
    }
    string ID() const
    {
        return m_id;
    }
    void GetId() const
    {
        cout << m_name << "'s id is " << m_id << " ." << endl;
    }
    void GetTotal() const
    {
        cout << m_name << "'s total grade is " << TotalGrade() << " ." << endl;
    }
    void GetAverage() const
    {
        cout << m_name << "'s average grade is " << AverageGrade() << " ." << endl;
    }
    void ShowStudent() const
    {
        cout << "id: " << m_id << endl
             << "name: " << m_name << endl
             << "language garde: " << m_lang << endl
             << "math grade: " << m_math << endl
             << "total grade: " << TotalGrade() << endl
             << "average grade: " << AverageGrade() << endl;
    }
    int operator>(Student &a)
    {
        return this->TotalGrade() > a.TotalGrade() ? 1 : 0;
    }
    /*修改成绩函数组*/
    void ChangeLanguage(int lang)
    {
        this->m_lang = lang;
    }
    void ChangeMath(int math)
    {
        this->m_math = math;
    }

private:
    string m_id;
    string m_name;
    int m_lang;
    int m_math;
};

class AutoLink
{
public:
    AutoLink(const Student &a) //构造函数
    {
        num++;
        man = a;

        this->next = head;
        head = this;
        cout << "Create a student information" << endl;
    }
    AutoLink(string ID, string NAME, int a, int b) : man(ID, NAME, a, b) //构造函数
    {
        num++;
        this->next = head;
        head = this;
        cout << "Create a student information" << endl;
    }
    //AutoLink(const AutoLink &a) {}            //拷贝构造函数
    //AutoLink &operator=(const AutoLink &a) {} //赋值运算符函数
    virtual ~AutoLink() //虚函数
    {
        AutoLink *pGuard = head;
        if (head == this)
            head = this->next;
        else
        {
            while (pGuard->next != this)
                pGuard = pGuard->next;
            pGuard->next = this->next;
        }
        num--;
        cout << "Delete the list successfully" << endl;
    }

    void ChangeAutoLinkFirst(Student &a)
    {
        head->man = a;
    }
    void ShowAutoLink() const //显示所有节点信息
    {
        cout << "Number of nodes: " << num << endl;
        for (AutoLink *p = head; p != NULL; p = p->next)
        {
            p->man.ShowStudent();
            cout << endl;
        }
    }
    Student GetStudent(string id) const
    {
        for (AutoLink *p = head; p != NULL; p = p->next)
        {
            if (p->man.ID() == id)
            {
                return p->man;
                break;
            }
        }
    }

    static AutoLink *GetHead()
    {
        return head;
    }

    static void ShowAll()
    {
        for (AutoLink *p = head; p != NULL; p = p->next)
        {
            p->man.ShowStudent();
            cout << endl;
        }
    }

    friend void ShowAll(AutoLink *HEAD);

private:
    Student man;
    AutoLink *next;
    static AutoLink *head;
    static int num;
};

AutoLink *AutoLink::head = NULL;
int AutoLink::num = 0;

void ShowAll(AutoLink *HEAD)
{
    for (AutoLink *p = HEAD; p != NULL; p = p->next)
    {
        p->man.ShowStudent();
        cout << endl;
    }
}

int main()
{
    string id, name;
    int lang, math, i = 0;
    Student Stu[4];
    /*read*/
    ifstream infile;
    infile.open("my_student.txt");
    while (i != 4)
    {
        infile >> id >> name >> lang >> math;
        Student a(id, name, lang, math);
        Stu[i] = a;
        i++;
    }
    AutoLink Stu1(Stu[0]), Stu2(Stu[1]), Stu3(Stu[2]), Stu4(Stu[3]);

    AutoLink::ShowAll();

    ShowAll(AutoLink::GetHead());
    AutoLink *HEAD = AutoLink::GetHead();
    Stu[0].ChangeLanguage(100);
    Stu[0].ChangeMath(100);
    HEAD->ChangeAutoLinkFirst(Stu[0]);
    AutoLink::ShowAll();
    ShowAll(AutoLink::GetHead());
    infile.close();
    system("pause");
}