/*

Code written with love by Kartik Arora

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0)
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

/****** Template of some basic operations *****/
template <typename T, typename U>
inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T>
inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x /= 10;
    } while (x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T>
inline T readInt()
{
    T n = 0, s = 1;
    char p = getchar();
    if (p == '-')
        s = -1;
    while ((p < '0' || p > '9') && p != EOF && p != '-')
        p = getchar();
    if (p == '-')
        s = -1, p = getchar();
    while (p >= '0' && p <= '9')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n * s;
}

int mex_value;

struct Graph
{
    int node_index;
    int node_value;
    vector<int> child_nodes;
};

int findMex(vector<int> values, int start, int end)
{
    if (start > end)
        return end + 1;
    if (start != values[start])
        return start;
    int mid = (start + end) / 2;
    if (values[mid] == mid)
        return findMex(values, mid + 1, end);
    else
        return findMex(values, start, mid);
}

void dfs_with_bs(Graph *graph, int current_node, set<int> visited, set<int> values, int n, set<int> anti_vis)
{
    visited.insert(current_node);
    // values.insert(graph[current_node].node_value);
    anti_vis.erase(graph[current_node].node_value);
    // cout << "Current Node: " << current_node << endl;
    // cout << "Values: ";
    // for (auto v : values)
    //     cout << v << " ";
    // cout << endl;

    // cout << "Minimum Value: " << *(anti_vis.begin()) << endl;
    int mex = *(anti_vis.begin());
    // vector<int> v(values.begin(), values.end());
    // int mex = findMex(v, 0, values.size() - 1);
    // int mex = INT32_MAX;
    // for (int i = 0; i <= values.size(); i++)
    // {
    //     if (values.find(i) == values.end())
    //     {
    //         mex = i;
    //         break;
    //     }
    // }

    mex_value = max(mex_value, mex);

    for (auto child : graph[current_node].child_nodes)
    {
        // cout << "Checking on Child: " << child << endl;
        if (visited.find(child) == visited.end())
        {
            dfs_with_bs(graph, child, visited, values, n, anti_vis);
        }
    }
}

void solve()
{
    mex_value = 0;
    int n;
    cin >> n;
    Graph *graph = new Graph[n];

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        graph[i].node_index = i;
        graph[i].node_value = val;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].child_nodes.emplace_back(b);
        graph[b].child_nodes.emplace_back(a);
    }

    set<int> visited, values, anti_vis;
    for (int i = 0; i <= n; i++)
    {
        anti_vis.insert(i);
    }

    dfs_with_bs(graph, 0, visited, values, n, anti_vis);

    // for (auto g : graph)
    // {
    //     cout << "Node Value: " << g.first << endl;
    //     for (auto child : g.second)
    //         cout << child << " ";
    //     cout << endl;
    // }
    cout << mex_value;
    delete[] graph;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}