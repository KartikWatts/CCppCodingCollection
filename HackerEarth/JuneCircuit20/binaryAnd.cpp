#include <iostream>
#include <vector>

using namespace std;

int totalOdds = 0;

void getPaths(int vertex, int total, vector<int> path)
{
    // if ((total % 2 == 0 && vertex > total / 2) || (total % 2 != 0 && vertex + 1 > total / 2))
    // {
    //     cout << "Final Path:\t";
    //     for (auto it : path)
    //     {
    //         cout << it << "-> ";
    //     }
    // }
    if (vertex <= total / 2)
    {
        int vt = vertex * 2;
        if (vt <= total)
        {
            path.push_back(vt);
            // for (auto it : path)
            // {
            //     cout << it << "-> ";
            // }
            // cout << endl;

            int tempAndValue = vt;

            for (int i = path.size() - 2; i >= 0; i--)
            {
                // cout << "AND operation performed b/w " << tempAndValue << " and " << path[i] << endl;
                tempAndValue &= path[i];
                if (tempAndValue % 2 != 0)
                {
                    totalOdds++;
                    // cout << "Odd found for:\t";
                    // for (int j = path.size() - 1; j >= i; j--)
                    // {
                    //     cout << path[j] << "-> ";
                    // }
                    // cout << endl;
                }
                else
                {
                    break;
                }
            }
            getPaths(vertex * 2, total, path);
        }
        if (vt + 1 <= total)
        {
            path.pop_back();
            path.push_back(vt + 1);
            // for (auto it : path)
            // {
            //     cout << it << "-> ";
            // }
            // cout << endl;
            int tempAndValue = vt + 1;

            for (int i = path.size() - 2; i >= 0; i--)
            {
                // cout << "AND operation performed b/w " << tempAndValue << " and " << path[i] << endl;
                tempAndValue &= path[i];
                if (tempAndValue % 2 != 0)
                {
                    totalOdds++;
                    // cout << "Odd found for:\t";
                    // for (int j = path.size() - 1; j >= i; j--)
                    // {
                    //     cout << path[j] << "-> ";
                    // }
                    // cout << endl;
                }
                else
                {
                    break;
                }
            }
            getPaths(vertex * 2 + 1, total, path);
        }
    }
}

int main()
{
    int q, n;
    cin >> q;
    while (q--)
    {
        totalOdds = 0;
        cin >> n;
        vector<int> path = {1};
        getPaths(1, n, path);
        cout << totalOdds << endl;
    }
}