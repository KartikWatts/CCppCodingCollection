#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMinNode(int v, map<int, map<int, int>> adj, int *distance, bool *visited)
{
    int minDistance = INT_MAX, minNode;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false && distance[i] < minDistance)
        {
            minDistance = distance[i];
            minNode = i;
        }
    }
    return minNode;
}

int main()
{
    int v, e;
    cin >> v >> e;
    map<int, map<int, int>> adj;
    for (int i = 0; i < e; i++)
    {
        int src, dst, wt;
        cin >> src >> dst >> wt;
        adj[src][dst] = wt;
        adj[dst][src] = wt;
    }

    map<int, map<int, int>>::iterator itr;
    map<int, int>::iterator ptr;

    // for (itr = adj.begin(); itr != adj.end(); itr++)
    // {
    //     for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
    //     {
    //         cout << itr->first << " " << ptr->first << " " << ptr->second << endl;
    //     }
    // }
    bool visited[v];
    int distance[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for (int i = 0; i < v; i++)
    {
        int node = getMinNode(v, adj, distance, visited);
        visited[node] = true;
        // cout << "Node Selected: " << node << endl;
        for (ptr = adj[node].begin(); ptr != adj[node].end(); ptr++)
        {
            int tempDist = distance[node] + ptr->second;
            if (distance[ptr->first] > tempDist)
            {
                distance[ptr->first] = tempDist;
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
}