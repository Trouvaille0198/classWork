#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    Point(double x = 0, double y = 0) : m_x(x), m_y(y) {}
    virtual void Show()
    {
        cout << "The point is at "
             << "( " << m_x << ", " << m_y << " )" << endl;
    }

private:
    double m_x;
    double m_y;
};

class Circle : public Point
{
public:
    Circle(double x, double y, double r = 1) : Point(x, y), m_r(r) {}
    Circle(Point p, double r = 1) : Point(p), m_r(r) {}
    double Getp()
    {
        double p = 2 * 3.14 * m_r;
        return p;
    }
    double Gets()
    {
        double s = 3.14 * m_r * m_r;
        return s;
    }
    void Showp()
    {
        cout << Getp() << endl;
    }
    void Shows()
    {

        cout << Gets() << endl;
    }

private:
    double m_r;
};

class Cylinder : public Circle
{
public:
    Cylinder(double x, double y, double r, double h) : Circle(x, y, r), m_h(h) {}
    Cylinder(Circle(c), double h) : Circle(c), m_h(h) {}
    double Gets()
    {
        double s = Circle::Getp() * m_h + 2 * Circle::Gets();
        return s;
    }
    double Getv()
    {
        double v = Circle::Gets() * m_h;
        return v;
    }
    void Shows()
    {
        cout << Gets() << endl;
    }
    void Showv()
    {
        cout << Getv() << endl;
    }

private:
    double m_h;
};

int main()
{
    Point p1(1, 2), p2(3, 4);
    Circle c1(p1, 4), c2(p2, 8);
    Cylinder cy1(c1, 6), cy2(c2, 10);
    c1.Showp();
    c1.Shows();
    cy1.Shows();
    cy1.Showv();
    system("pause");
}