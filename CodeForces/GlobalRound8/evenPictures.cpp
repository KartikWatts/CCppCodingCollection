#include <iostream>
#include <math.h>

typedef unsigned long long ull;
using namespace std;

struct Squares
{
    ull row, col;
};

int main()
{
    int n;
    cin >> n;
    ull checkSquare = 2, totalSquares = 0;
    while (pow(checkSquare, 2) < n)
    {
        checkSquare += 2;
    }
    ull squareNumber = pow(checkSquare, 2);
    // cout << "Satisfy for square of: " << checkSquare << endl;
    totalSquares = squareNumber;
    ull term = checkSquare, extraRows = 0;
    while (term >= 2)
    {
        totalSquares += 4 * term;
        term -= 2;
        extraRows++;
    }
    cout << totalSquares << endl;
    Squares s[totalSquares];
    ull a[checkSquare][checkSquare];
    ull maxLen = checkSquare + 2 * extraRows;
    // cout << "Max Len: " << maxLen << endl;
    ull index = 0;
    for (ull i = 0; i < maxLen / 2; i++)
    {
        for (ull j = 0; j < maxLen; j++)
        {
            if (j >= checkSquare - i - 1 && j < checkSquare + i + 1)
            {
                // cout << "*";
                s[index].row = i;
                s[index].col = j;
                index++;
            }
            else
            {
                // cout << " ";
            }
        }
        // cout << endl;
    }

    for (ull i = maxLen / 2; i < maxLen; i++)
    {
        ull temp = i - maxLen / 2;
        for (ull j = 0; j < maxLen; j++)
        {
            if (j >= temp && j < maxLen - temp)
            {
                // cout << "*";
                s[index].row = i;
                s[index].col = j;
                index++;
            }
            else
            {
                // cout << " ";
            }
        }
        // cout << endl;
    }
    for (ull i = 0; i < totalSquares; i++)
    {
        cout << s[i].row << " " << s[i].col << endl;
    }
}