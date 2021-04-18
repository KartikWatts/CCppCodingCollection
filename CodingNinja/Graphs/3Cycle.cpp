#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int finalAns = 0;

void print(int **adj, int V, queue<int> &q, bool *visited, vector<int> &visitTracker, int start, int len)
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
            if (len == 2 && adj[node][i] == 1 && i == start)
            {
                finalAns++;
            }
            if (adj[node][i] == 1 && visited[i] == false)
            {
                len++;
                q.push(i);
                visited[i] = true;
                print(adj, V, q, visited, visitTracker, start, len);
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
    while (visitTracker.size() > 0)
    {
        it = visitTracker.begin();
        q.push(*it);
        visited[*it] = true;
        int len = 0;
        print(adj, n, q, visited, visitTracker, *it, len);
    }

    for (int i = 0; i < n; i++)
    {
        delete[] adj[i];
    }

    delete[] adj;
    delete[] visited;
    return finalAns;
}

int main()
{
    int n, m;
    vector<int> u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        u.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solve(n, m, u, v) << endl;
}