#include <iostream>
#include <vector>

using namespace std;

int gY = 0;

void backTrackFun(int x, int y, int n, vector<vector<bool>> possible, vector<vector<int>> result)
{
    // cout << "Currently on Point (" << x << ", " << y << ")" << endl;
    if (x < n && y < n)
        result[x][y] = 1;
    if (x < n && y < n)
        possible[x][y] = false;
    int i = x, j = y;
    while (i < n && j < n)
    {
        possible[x][j++] = false;
    }
    i = x, j = y;
    while (i < n && j < n)
    {
        possible[i++][y] = false;
    }
    i = x, j = y;
    while (i < n && j < n)
    {
        possible[i++][j++] = false;
    }
    i = x, j = y;
    while (i < n && j >= 0)
    {
        possible[i++][j--] = false;
    }

    if (x == n - 1)
    {
        // cout << "Got a Result as:" << endl;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                cout << result[j][i] << " ";
        }
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                possible[i][j] = true;
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                result[j][i] = 0;
        }

        if (gY + 1 < n)
        {
            gY++;
            backTrackFun(0, gY, n, possible, result);
        }
    }
    else
    {
        i = 0;
        for (i = 0; i < n; i++)
        {
            if ((x + 1 < n) && possible[x + 1][i] == true)
            {
                backTrackFun(x + 1, i, n, possible, result);
            }
        }
        if (i == n)
        {
            // cout << "No possible Column found for Row " << x + 1 << endl;
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n; i++)
                    possible[i][j] = true;
            }
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n; i++)
                    result[j][i] = 0;
            }
            if (gY + 1 < n)
            {
                gY++;
                backTrackFun(0, gY, n, possible, result);
            }
        }
    }
}

void placeNQueens(int n)
{
    vector<vector<bool>> possible(n);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
            possible[j].push_back(true);
    }
    vector<vector<int>> result(n);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
            result[j].push_back(0);
    }
    backTrackFun(0, 0, n, possible, result);
}

int main()
{
    int n;
    cin >> n;
    placeNQueens(n);
}