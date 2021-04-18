#include <iostream>

using namespace std;

// int limitExe = 0;

bool isValidHorizontal(int k, int x, int a[][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (a[x][i] == k)
            return false;
    }
    return true;
}

bool isValidVertical(int k, int y, int a[][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (a[i][y] == k)
            return false;
    }
    return true;
}

bool isValidGrid(int k, int x, int y, int a[][9])
{
    for (int i = (x - x % 3); i < (x - x % 3) + 3; i++)
    {
        for (int j = (y - y % 3); j < (y - y % 3) + 3; j++)
        {
            if (a[i][j] == k)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(int board[][9])
{

    // if (limitExe >= 20)
    //     return false;

    /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */

    bool finished = true;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                finished = false;
                // cout << "0 Found at (" << i << ", " << j << ")" << endl;
                // limitExe++;
                for (int k = 1; k <= 9; k++)
                {
                    if (isValidHorizontal(k, i, board) && isValidVertical(k, j, board) && isValidGrid(k, i, j, board))
                    {
                        // cout << "Filling number: " << k << " at (" << i << ", " << j << ")" << endl;
                        board[i][j] = k;
                        if (sudokuSolver(board))
                        {
                            // cout << "Filled number correctly: " << k << " at (" << i << ", " << j << ")" << endl;
                            return true;
                        }
                        else
                        {
                            // cout << "Can't fill: " << k << " at (" << i << ", " << j << ")" << endl;
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }

    if (finished == true)
    {
        // cout << "Resulting Sudoku:: " << endl;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }

        return true;
    }
    return false;
}

int main()
{
    string s[9];
    for (int i = 0; i < 9; i++)
        cin >> s[i];
    int sudoku[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku[i][j] = s[i][j] - '0';
        }
    }

    sudokuSolver(sudoku);
}