#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int totalPaths = 0;
map<pair<int, int>, int> res;

bool getPaths(char **a, int n, int m, vector<pair<int, int>> p)
{
    int x = p.back().first, y = p.back().second;
    if (x == n - 1 && y == m - 1)
    {
        totalPaths++;
        // cout << "Path found" << endl;
        for (auto it : p)
        {
            // cout << "(" << it.first << ", " << it.second << ") -> ";
            res[make_pair(it.first, it.second)]++;
        }
        // cout << endl;
        return true;
    }
    // cout << "Finding path from Point: " << x << ", " << y << endl;
    bool pDown = false, pRight = false;
    if (a[x][y] == '#')
    {
        return false;
    }
    else
    {
        if ((y + 1 != m) && a[x][y + 1] == '.')
        {
            // cout << "Current Point: " << x << ", " << y << "\tChecking Point: " << x << ", " << y + 1 << endl;
            p.push_back(make_pair(x, y + 1));
            pRight = getPaths(a, n, m, p);
            if (pRight)
            {
                // return true;
            }
            else
            {
                p.pop_back();
            }
        }
        if ((x + 1 != n) && a[x + 1][y] == '.')
        {
            // cout << "Current Point: " << x << ", " << y << "\tChecking Point: " << x + 1 << ", " << y << endl;
            if (pRight)
                p.pop_back();
            p.push_back(make_pair(x + 1, y));
            pDown = getPaths(a, n, m, p);
            if (pDown)
            {
                // return true;
            }
            else
            {
                p.pop_back();
            }
        }
        if (pRight || pDown)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    char **a;
    a = new char *[n];
    for (int i = 0; i < m; i++)
    {
        a[i] = new char[m];
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> p;
    p.push_back(make_pair(0, 0));
    getPaths(a, n, m, p);
    // cout << "Total Paths: " << totalPaths;
    // cout << "Resulting Map:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (res[{i, j}] == totalPaths)
            {
                cout << "0 ";
            }
            else
            {
                cout << "1 ";
            }
        }
        cout << endl;
    }
}