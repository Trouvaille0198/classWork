#include <iostream>
using namespace std;
void ShowInt(unsigned int n, int base = 10)
{
    static char BASE[17] = "0123456789ABCDEF";
    if (n != 0)
        ShowInt(n / base, base);
    else
        return;
    cout << BASE[n % base];
}

int main()
{
    ShowInt(127);
    cout << endl;
    ShowInt(127, 2);
    cout << endl;
    ShowInt(127, 8);
    cout << endl;
    ShowInt(127, 16);
    cout << endl;
    system("pause");
}