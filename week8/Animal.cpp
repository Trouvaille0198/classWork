#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    virtual void Sound() const {};
};
class Cat : public Animal
{
public:
    void Sound() const
    {
        cout << "miaow ..." << endl;
    }
};
class Dog : public Animal
{
public:
    void Sound() const
    {
        cout << "wang ..." << endl;
    }
};
class Rooster : public Animal
{
public:
    void Sound() const
    {
        cout << "crow ..." << endl;
    }
};
class Cattle : public Animal
{
public:
    void Sound() const
    {
        cout << "moo ..." << endl;
    }
};
class Horse : public Animal
{
public:
    void Sound() const
    {
        cout << "neigh ..." << endl;
    }
};

void Speaker(const Animal &a)
{
    a.Sound();
}
void Speaker(const Animal *a)
{
    a->Sound();
}

int main()
{
    Cat cat1;
    Cattle cattle1, &p = cattle1;
    Speaker(cat1);
    Speaker(p);
    system("pause");
}