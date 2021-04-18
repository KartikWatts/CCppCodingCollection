#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        char res[8][8];
        int row = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                res[i][j] = '.';
            }
        }
        res[0][0] = 'O';

        while (k > 8)
        {
            // cout << "k= " << k << endl;
            for (int i = 0; i < 8; i++)
            {
                res[row][i] = '.';
                if (row == 0)
                {
                    res[row][0] = 'O';
                }
            }
            row++;
            k -= 8;
        }
        int col = 0;

        // cout << "k= " << k << endl;
        for (int i = 0; i < k; i++)
        {
            res[row][i] = '.';
            if (row == 0)
            {
                res[row][0] = 'O';
            }
            col = i;
            // cout << "COL: " << col << endl;
        }
        if (col < 7)
        {
            for (int i = col + 1; i < 8; i++)
            {
                res[row][i] = 'X';
            }
        }
        if (row < 7)
        {
            row++;
            if (col < 6)
            {
                for (int i = 0; i < col + 2; i++)
                {
                    res[row][i] = 'X';
                }
            }
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    res[row][i] = 'X';
                }
            }
        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << res[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}