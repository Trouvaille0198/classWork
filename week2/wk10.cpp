#include <bits/stdc++.h>
using namespace std;

int Sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int cmpInt(const void *a, const void *b)
{
    return Sum(*(int *)a) - Sum(*(int *)b);
}
int cmpDouble(const void *a, const void *b)
{
    return *(double *)a - *(double *)b;
}
int cmpChar(const void *a, const void *b)
{
    int size1 = strlen(*(char **)a);
    int size2 = strlen(*(char **)b);
    if (size1 > size2)
        return 1;
    else if (size1 == size2)
        return strcmp(*(char **)a, *(char **)b);
    else
        return -1;
}

int main()
{
    int a[10] = {12, 32, 42, 51, 8, 16, 51, 21, 19, 9};
    double b[10] = {32.1, 456.87, 332.67, 442.0, 98.12, 451.79, 340.12, 54.55, 99.87, 72.5};
    char *c[10] = {"enter", "number", "size", "begin", "of", "cat", "case", "program", "certain", "a"};
    /*  Sort int */
    qsort(a, 10, sizeof(int), cmpInt);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    /* Sort double */
    qsort(b, 10, sizeof(double), cmpDouble);
    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    /* Sort string */
    qsort(c, 10, sizeof(*c), cmpChar);
    for (int i = 0; i < 10; i++)
    {
        cout << c[i] << " ";
    }
    system("pause");
}