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
    void Show();
    /*双目运算符重载*/
    template <typename TYPE>
    friend Vector<TYPE> operator+(const Vector<TYPE> &v1, const Vector<TYPE> &v2);
    template <typename TYPE>
    friend Vector<TYPE> operator-(const Vector<TYPE> &v1, const Vector<TYPE> &v2);
    template <typename TYPE>
    friend Vector<TYPE> operator*(const TYPE &a, const Vector<TYPE> &v1);
    template <typename TYPE>
    friend Vector<TYPE> operator*(const Vector<TYPE> &v1, const TYPE &a);
    Vector<T> &operator+=(const Vector<T> &v1);
    Vector<T> &operator-=(const Vector<T> &v1);
    /*单目运算符重载*/
    Vector<T> &operator++(); //前置++
    Vector<T> &operator--(); //前置--
    Vector<T> operator++(T); //后置++
    Vector<T> operator--(T); //后置--

    T &operator[](int index) const; //下标运算符

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
void Vector<T>::Show()
{
    cout << "此" << m_len << "维数组的坐标为: (";
    for (int i = 0; i < m_len - 1; i++)
    {
        cout << m_coor[i] << ", ";
    }
    cout << m_coor[m_len - 1] << ")" << endl;
}

template <typename T>
Vector<T> operator+(const Vector<T> &v1, const Vector<T> &v2)
{
    Vector<T> result(v1);
    if (v1.m_len != v2.m_len)
        return result;

    for (int i = 0; i < result.m_len; i++)
    {
        result[i] += v2[i];
    }
    return result;
}

template <typename T>
Vector<T> operator-(const Vector<T> &v1, const Vector<T> &v2)
{
    Vector<T> result(v1);
    if (v1.m_len != v2.m_len)
        return result;

    for (int i = 0; i < result.m_len; i++)
    {
        result[i] -= v2[i];
    }
    return result;
}

template <typename T>
Vector<T> operator*(const T &a, const Vector<T> &v1)
{
    Vector<T> result(v1);

    for (int i = 0; i < v1.m_len; i++)
    {
        result.m_coor[i] = a * v1.m_coor[i];
    }
    return result;
}

template <typename T>
Vector<T> operator*(const Vector<T> &v1, const T &a)
{
    return a * v1;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &v1)
{
    return *this = *this + v1;
}

template <typename T>
Vector<T> &Vector<T>::operator-=(const Vector<T> &v1)
{
    return *this = *this - v1;
}

template <typename T>
Vector<T> &Vector<T>::operator++()
{
    for (int i = 0; i < m_len; i++)
    {
        m_coor[i]++;
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator--()
{
    for (int i = 0; i < m_len; i++)
    {
        m_coor[i]--;
    }
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator++(T)
{
    Vector<T> result(*this); //拷贝构造
    ++(*this);               //利用前置运算符重载函数
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator--(T)
{
    Vector<T> result(*this); //拷贝构造
    --(*this);               //利用前置运算符重载函数
    return *this;
}

template <typename T>
T &Vector<T>::operator[](int index) const
{
    return m_coor[index];
}

#endif