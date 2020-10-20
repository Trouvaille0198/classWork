#include "Vector.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[4] = {0, 2, 4, 6};
    int b[4] = {1, 4, 6, 8};

    Vector<int> vec1(a, 4), vec2(b, 4);
    Vector<int> vec3(vec1 - vec2);
    vec3.Show();
    system("pause");
}