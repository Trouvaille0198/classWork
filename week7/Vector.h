#ifndef VECTOR_H
#define VECTOR_H
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector
{
public:
    Vector(T *coor = NULL, int len = 0);
    Vector(const Vector<T> &N);
    ~Vector();
    Vector &operator=(const Vector<T> &N);
    template <typename T>
    friend Vector<T> operator+(const Vector<T> &v1, const Vector<T> &v2);
    friend Vector<T> operator-(const Vector<T> &v1, const Vector<T> &v2);
    friend Vector<T> operator*(const Vector<T> &v1, const Vector<T> &v2);
    friend Vector<T> operator/(const Vector<T> &v1, const Vector<T> &v2);

private:
    T *m_coor;
    int m_len;
};

template <typename T>
Vector<T>::Vector(T *coor, int len)
{
    //int len = sizeof(coor) / sizeof(coor[0]); //不可行，辣鸡C++
    m_len = len;
    m_coor = new T[len];
    for (int i = 0; i < m_len; i++)
    {
        m_coor[i] = coor[i];
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &N)
{
    /*     m_len = N.m_len;
    m_coor = new int[m_len];
    for (int i = 0; i < m_len; i++)
    {
        m_coor[i] = N.m_coor[i];
    } */

    m_len = 0;
    m_coor = NULL;
    *this = N;
}

template <typename T>
Vector<T>::~Vector()
{
    m_len = 0;
    if (m_coor != NULL)
        delete[] m_coor;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &N)
{
    m_len = N.m_len;
    m_coor = new int[m_len];
    for (int i = 0; i < m_len; i++)
    {
        m_coor[i] = N.m_coor[i];
    }
    return *this;
}

template <typename T>
Vector<T> operator+(const Vector<T> &v1, const Vector<T> &v2)
{
    Vector<T> result;
    if (v1.m_len != v2.m_len)
        return result;

    result.m_len = v1.m_len;
    result.m_coor = new int[result.m_len];
    for (int i = 0; i < len; i++)
    {
        result.m_coor[i] = v1.m_coor[i] + v2.m_coor[i];
    }
    return result;
}

template <typename T>
Vector<T> operator-(const Vector<T> &v1, const Vector<T> &v2)
{
}

template <typename T>
Vector<T> operator*(const Vector<T> &v1, const Vector<T> &v2)
{
}

template <typename T>
Vector<T> operator/(const Vector<T> &v1, const Vector<T> &v2)
{
}

#endif