#include <bits/stdc++.h>
using namespace std;

void getSaddlePoint(int ma[5][5])
{

    int flag = 0;
    //r=row, c=colomn

    //大行小列
    for (int r = 0; r < 5; r++)
    {
        int judge = 1;
        int flagColomn = 0;
        int max = ma[r][0];
        for (int c = 0; c < 5; c++) //遍历第r行
        {
            if (ma[r][c] > max)
            {
                max = ma[r][c];
                flagColomn = c;
            }
        }

        for (int i = 0; i < 5; i++)
        {
            if (ma[i][flagColomn] < max)
            {
                judge = 0;
                break;
            }
        }
        if (judge)
        {
            cout << "Found a saddle point1 " << max << endl;
            flag = 1;
        }
    }

    //小行大列
    for (int r = 0; r < 5; r++)
    {
        int judge = 1;
        int flagRow = 0;
        int min = ma[r][0];
        for (int c = 0; c < 5; c++) //遍历第r行
        {
            if (ma[r][c] < min)
            {
                min = ma[r][c];
                flagRow = c;
            }
        }

        for (int i = 0; i < 5; i++)
        {
            if (ma[i][flagRow] > min)
            {
                judge = 0;
                break;
            }
        }
        if (judge)
        {
            cout << "Found a saddle point2 " << min << endl;
            flag = 1;
        }
    }

    if (flag == 0)
        cout << "No saddle point in this matrix" << endl;
}

int main()
{
    for (int i = 0; i < 50; i++)
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

        getSaddlePoint(ma);
    }
    getchar();
    getchar();
}