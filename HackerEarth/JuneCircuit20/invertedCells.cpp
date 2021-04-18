#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;

struct point
{
    int x;
    int y;
};

vvi explore(vvc v, point st, point end, vvi res)
{
    if ()
        return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vvc v(n);
    point stPoint, endPoint;
    stPoint.x = 0;
    stPoint.y = 0;
    endPoint.x = n - 1;
    endPoint.y = m - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    }

    for (auto it : v)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    vvi res(n);

    if (v[0][0] != '#' && v[n - 1][m - 1] != '#')
    {
        res = explore(v, stPoint, endPoint, res);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i].push_back(0);
            }
        }
    }

    for (auto it : res)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    // explore(v, stPoint, endPoint, res);
}