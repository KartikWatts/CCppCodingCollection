#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> dfs(bool *&visited, stack<int> st, vector<int> *adj, vector<int> tempComp)
{
    while (!st.empty())
    {
        int node = st.top();
        tempComp.push_back(node);
        st.pop();
        for (auto it : adj[node])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                st.push(it);
                dfs(visited, st, adj, tempComp);
            }
        }
    }
    return tempComp;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int p[n], q[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        vector<int> adj[n];
        vector<vector<int>> components;
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                st.push(i);
                vector<int> tempComp;
                components.push_back(dfs(visited, st, adj, tempComp));
            }
        }
        bool isEqual = true;
        for (auto it : components)
        {
            vector<int> comp1, comp2;
            for (auto it2 : it)
            {
                // cout << it2 << " ";
                comp1.push_back(p[it2]);
                comp2.push_back(q[it2]);
            }
            sort(comp1.begin(), comp1.end());
            sort(comp2.begin(), comp2.end());
            for (int i = 0; i < comp1.size(); i++)
            {
                if (comp1[i] != comp2[i])
                {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual == false)
            {
                break;
            }
            comp1.clear();
            comp2.clear();
        }
        if (isEqual)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}