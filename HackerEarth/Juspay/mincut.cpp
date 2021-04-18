// C++ program for finding minimum cut using Ford-Fulkerson
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

/* Returns true if there is a path from source 's' to sink 't' in 
  residual graph. Also fills parent[] to store the path */
int bfs(int *rGraph, int s, int t, int parent[], int n)
{
    // Create a visited array and mark all vertices as not visited
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.  The initial values in
// visited[] must be false. We can also use BFS to find reachable vertices
void dfs(int **rGraph, int s, bool visited[], int n)
{
    visited[s] = true;
    for (int i = 0; i < n; i++)
        if (rGraph[s][i] && !visited[i])
            dfs(rGraph, i, visited, n);
}

// Prints the minimum s-t cut
void minCut(int **graph, int s, int t, int size)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[size][size]; // rGraph[i][j] indicates residual capacity of edge i-j
    for (u = 0; u < size; u++)
        for (v = 0; v < size; v++)
            rGraph[u][v] = graph[u][v];

    int parent[size]; // This array is filled by BFS and to store path

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent, size))
    {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }

    // Flow is maximum now, find vertices reachable from s
    bool visited[size];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited, size);

    // Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < V; j++)
            if (visited[i] && !visited[j] && graph[i][j])
                cout << i << " - " << j << endl;

    return;
}

// Driver program to test above functions
int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        m.insert({temp, i});
    }
    int graph[n][n];
    // Let us create a graph shown in the above example

    int e;
    cin >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[m[a]][m[b]] = 1;
        graph[m[b]][m[a]] = 1;
    }
    int A, B;
    cin >> A >> B;
    minCut(graph, A, B, n);

    return 0;
}