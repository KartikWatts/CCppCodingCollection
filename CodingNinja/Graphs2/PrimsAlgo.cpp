#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    int **adj = new int *[v];
    for (int i = 0; i < v; i++)
    {
        adj[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            adj[i][j] = -1;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1][v2] = w;
        adj[v2][v1] = w;
    }

    int weight[v], parent[v];
    vector<int> unvisited;
    int node = 0;
    weight[0] = -1, parent[0] = 0;

    for (int i = 1; i < v; i++)
    {
        weight[i] = INT_MAX;
        unvisited.push_back(i);
    }

    while (!unvisited.empty())
    {
        for (int i = 0; i < v; i++)
        {
            if (i != node && adj[node][i] != -1 && find(unvisited.begin(), unvisited.end(), i) != unvisited.end())
            {
                if (adj[node][i] < weight[i])
                {
                    weight[i] = adj[node][i];
                    if (i == 0)
                        parent[i] = 0;
                    else
                        parent[i] = node;
                }
            }
        }
        int minWeight = INT_MAX;
        vector<int>::iterator it;
        for (int i = 0; i < v; i++)
        {
            it = find(unvisited.begin(), unvisited.end(), i);
            if (it != unvisited.end())
            {
                if (weight[i] < minWeight)
                {
                    minWeight = weight[i];
                    node = i;
                }
            }
        }
        it = find(unvisited.begin(), unvisited.end(), node);
        unvisited.erase(it);
    }

    for (int i = 1; i < v; i++)
    {
        if (i < parent[i])
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
        else
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
    }

    for (int i = 0; i < v; i++)
    {
        delete[] adj[i];
    }
    delete[] adj;
}