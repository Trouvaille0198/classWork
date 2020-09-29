#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int *m_x, *m_y;

public:
    Point(int x = 0, int y = 0);
    Point(const Point &N);
    Point &operator=(const Point &N);
    ~Point();
    void Show() const;
    void Set();
};

#endif