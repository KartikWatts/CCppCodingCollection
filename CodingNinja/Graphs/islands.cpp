#include <bits/stdc++.h>
using namespace std;

void print(int **adj, int V, queue<int> &q, bool *visited, vector<int> &visitTracker)
{
    while (q.size() > 0)
    {
        int node = q.front();
        q.pop();
        vector<int>::iterator it;
        it = find(visitTracker.begin(), visitTracker.end(), node);
        visitTracker.erase(it);
        for (int i = 0; i < V; i++)
        {
            if (adj[node][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int solve(int n, int m, vector<int> u, vector<int> v)
{
    // Write your code here .
    int **adj = new int *[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
    bool *visited = new bool[n];
    vector<int> visitTracker;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        visitTracker.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        adj[u[i] - 1][v[i] - 1] = 1;
        adj[v[i] - 1][u[i] - 1] = 1;
    }
    queue<int> q;
    vector<int>::iterator it;
    int finalAns = 0;
    while (visitTracker.size() > 0)
    {
        it = visitTracker.begin();
        q.push(*it);
        visited[*it] = true;
        print(adj, n, q, visited, visitTracker);
        finalAns++;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] adj[i];
    }

    delete[] adj;
    delete[] visited;
    return finalAns;
}