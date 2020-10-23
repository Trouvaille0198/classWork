#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
    //creat a random matrix
    int ma[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            ma[i][j] = rand() % 100;
        }
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 4)
                cout << setw(5) << ma[i][j] << endl;
            else
                cout << setw(5) << ma[i][j] << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 4)
                cout << setw(5) << ma[j][i] << endl;
            else
                cout << setw(5) << ma[j][i] << " ";
        }
    }

    system("pause");
}
