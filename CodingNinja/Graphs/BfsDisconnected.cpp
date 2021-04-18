#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

void print(int **adj, int V, queue<int> &q, bool *visited, vector<int> &visitTracker)
{
    if (q.size() > 0)
    {
        // cout << "Queue: ";
        // showq(q);
        int node = q.front();
        // cout << "Abhi ke liye " << node << "\t";
        q.pop();
        vector<int>::iterator it;
        it = find(visitTracker.begin(), visitTracker.end(), node);
        visitTracker.erase(it);
        cout << node << " ";
        for (int i = 0; i < V; i++)
        {
            if (adj[node][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
        print(adj, V, q, visited, visitTracker);
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    int **adj = new int *[V];
    for (int i = 0; i < V; i++)
    {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    bool *visited = new bool[V];
    vector<int> visitTracker;
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        visitTracker.push_back(i);
    }

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    queue<int> q;
    vector<int>::iterator it;
    while (visitTracker.size() > 0)
    {
        it = visitTracker.begin();
        q.push(*it);
        visited[*it] = true;
        // cout << "Starting with " << *it << endl;
        print(adj, V, q, visited, visitTracker);
    }

    for (int i = 0; i < V; i++)
    {
        delete[] adj[i];
    }

    delete[] adj;
    delete[] visited;

    return 0;
}
