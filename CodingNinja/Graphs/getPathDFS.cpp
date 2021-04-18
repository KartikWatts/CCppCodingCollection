#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool getPathDFS(int V, int v2, bool *visited, int **adj, stack<int> st)
{
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        for (int i = 0; i < V; i++)
        {
            if (adj[node][i] == 1 && visited[i] == false)
            {
                if (i == v2)
                {
                    cout << v2 << " " << node << " ";
                    return true;
                }
                st.push(i);
                visited[i] = true;
                if (getPathDFS(V, v2, visited, adj, st) == true)
                {
                    cout << node << " ";
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int V, E, v1, v2;
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
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    cin >> v1 >> v2;

    stack<int> st;
    st.push(v1);
    visited[v1] = true;

    getPathDFS(V, v2, visited, adj, st);

    for (int i = 0; i < V; i++)
    {
        delete[] adj[i];
    }

    delete[] adj;
    delete[] visited;

    return 0;
}
