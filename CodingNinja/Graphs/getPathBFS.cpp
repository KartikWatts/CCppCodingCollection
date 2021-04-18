#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> result;
map<int, int> nodeMap;

void getPathBFS(int V, int v1, int v2, bool *visited, int **adj, queue<int> st)
{
    while (!st.empty())
    {
        int node = st.front();
        st.pop();
        for (int i = 0; i < V; i++)
        {
            if (adj[node][i] == 1 && visited[i] == false)
            {
                nodeMap[i] = node;
                if (i == v2)
                {
                    vector<int> tempRes;
                    int tempNode = i;
                    tempRes.push_back(v2);
                    while (tempNode != v1)
                    {
                        tempRes.push_back(nodeMap[tempNode]);
                        tempNode = nodeMap[tempNode];
                    }
                    if (result.size() == 0)
                    {
                        result = tempRes;
                    }
                    else
                    {
                        if (tempRes.size() < result.size())
                        {
                            result = tempRes;
                        }
                    }
                    return;
                }
                st.push(i);
                visited[i] = true;
                // getPathBFS(V, v1, v2, visited, adj, st);
            }
        }
    }
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

    queue<int> st;
    st.push(v1);
    visited[v1] = true;

    getPathBFS(V, v1, v2, visited, adj, st);

    for (auto it : result)
    {
        cout << it << " ";
    }

    for (int i = 0; i < V; i++)
    {
        delete[] adj[i];
    }

    delete[] adj;
    delete[] visited;

    return 0;
}
