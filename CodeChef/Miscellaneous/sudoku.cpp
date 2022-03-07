#include <iostream>
#define N 9

using namespace std;

bool solveSudoku(string sudo[N + 1])
{
    int x, y;
    bool foundEmpty = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (sudo[i][j] == '0')
            {
                x = i, y = j;
                foundEmpty = true;
                break;
            }
            if (foundEmpty)
                break;
        }
    }
    if (!foundEmpty)
    {
        // cout << "Not Found Empty" << endl;
        for (int i = 0; i < N; i++)
        {
            cout << sudo[i] << endl;
        }
        // cout << endl;
        return true;
    }
    else
    {
        // cout << "Found Empty at " << x << ", " << y << endl;
        int foundNumber = -1;
        int i = 1;
        while (i <= N)
        {
            // cout << "Finding Number " << char(48 + i) << endl;
            bool possible = true;
            int found = sudo[x].find(char(48 + i));
            if (found != string::npos)
            {
                possible = false;
                // cout << char(48 + i) << " Not Possible. Failed Case 1" << endl;
            }

            if (possible)
            {
                for (int k = 0; k < N; k++)
                {
                    if (sudo[k][y] == char(48 + i))
                    {
                        possible = false;
                        // cout << char(48 + i) << " Not Possible. Failed Case 2" << endl;
                        break;
                    }
                }
            }
            if (possible)
            {
                int xSector = x / 3, ySector = y / 3;
                xSector = 3 * xSector, ySector = 3 * ySector;
                for (int k = xSector; k < xSector + 3; k++)
                {
                    for (int j = ySector; j < ySector + 3; j++)
                    {
                        if (sudo[k][j] == char(48 + i))
                        {
                            possible = false;
                            // cout << char(48 + i) << " Not Possible. Failed Case 3" << endl;
                            break;
                        }
                    }
                }
            }
            if (possible)
            {
                foundNumber = i;
                if (foundNumber != -1)
                {
                    // cout << "Inserting number " << foundNumber << " at " << x << ", " << y << endl;
                    sudo[x][y] = char(48 + foundNumber);
                    if (solveSudoku(sudo) == true)
                        return true;
                    else
                    {
                        sudo[x][y] = 0;
                    }
                }
            }
            i++;
        }
    }
    return false;
}

int main()
{
    string sudo[N + 1];
    for (int i = 0; i < N; i++)
    {
        cin >> sudo[i];
    }

    solveSudoku(sudo);
}