#include <bits/stdc++.h>
using namespace std;

template <typename T>
void ShowTypeSize(const char *type, T x)
{
    int num = sizeof(x);
    cout << "sizeof(" << type << "):  " << num << " byte(s)" << endl;
}

int main()
{
    ShowTypeSize("int", int(1));
    ShowTypeSize("double",double(1));
    getchar();
    getchar();
}