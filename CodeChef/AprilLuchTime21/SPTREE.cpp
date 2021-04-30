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
#include <utility>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define ScanInt(t) scanf("%d", &t)
#define ScanLongInt(t) scanf("%ld", &t)
#define ScanLongLongInt(t) scanf("%lld", &t)
#define ScanUnsignedLongLong(t) scanf("%llu", &t)
#define ScanChar(t) scanf("%c", &t)
#define ScanString(t) scanf("%s", t)
#define ScanFloat(t) scanf("%f", &t)
#define ScanDouble(t) scanf("%lf", &t)
#define ScanStringSpace(t) getline(cin, t)

#define numberOfDigits(t) floor(log10(t)) + 1
#define issPowerOf2(t) (t && (!(t & (t - 1))))

typedef long long int ll;
typedef unsigned long long int ull;

template <typename T>
bool inline ifEven(T x)
{
    if (x & 1)
        return false;
    else
        return true;
}

template <typename T>
T inline multiplyBy2(T x)
{
    return x << 1;
}

template <typename T>
T inline divideBy2(T x)
{
    return x >> 1;
}

template <typename T>
T inline mostSignificantDigit(T x)
{
    double k = log10(x);
    k = k - floor(k);
    int res = pow(10, k);
    return res;
}

/****** Template of Fast I/O Methods *********/
template <typename T>
inline void writeInt(T x)
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

void readInt(int &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c == '-')
    {
        negative = true;

        c = getchar();
    }

    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    if (negative)
        number *= -1;
}

int minEdgeBFS(vector<int> edges[], int u,
               int v, int n)
{
    // visited[n] for keeping track of visited
    // node in BFS
    vector<bool> visited(n, 0);

    // Initialize distances as 0
    vector<int> distance(n, 0);

    // queue to do BFS.
    queue<int> Q;
    distance[u] = 0;

    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for (int i = 0; i < edges[x].size(); i++)
        {
            if (visited[edges[x][i]])
                continue;

            // update distance for i
            distance[edges[x][i]] = distance[x] + 1;
            Q.push(edges[x][i]);
            visited[edges[x][i]] = 1;
        }
    }
    return distance[v];
}

void addEdge(vector<int> edges[], int u, int v)
{
    edges[u].push_back(v);
    edges[v].push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a;
        cin >> n >> k >> a;
        a = a - 1;
        int special[k];
        for (int i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            special[i] = temp - 1;
        }
        int sp_dist[n][k];

        vector<int> edges[n];
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            addEdge(edges, u - 1, v - 1);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    sp_dist[i][j] = minEdgeBFS(edges, i, special[j], n);
                }
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < k; j++)
        //     {
        //         cout << i << "-> " << special[j] << ": " << sp_dist[i][j] << "\n";
        //     }
        //     cout << "\n\n";
        // }

        int max_special_node[n];
        for (int i = 0; i < n; i++)
        {
            int max = INT_MIN;
            for (int j = 0; j < k; j++)
            {
                if (sp_dist[a][j] - sp_dist[i][j] > max)
                {
                    max = sp_dist[a][j] - sp_dist[i][j];
                    max_special_node[i] = special[j] + 1;
                }
            }
            cout << max << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << max_special_node[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}