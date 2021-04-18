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

struct nodes
{
    ll stamina;
    ll sleep;
    vector<pair<int, ll>> edges;
    ll minStaminatoProceed;
};

ll minSleep = pow(10, 14);
int ind = 0;

void getPaths(int src, int dest, nodes *node, map<int, map<int, int>> paths, ll stamina, ll sleepHours)
{
    ind++;
    // cout << ind << ". Checking for Node: " << src << "\n";
    //IF DESTINATION IS REACHED
    if (src == dest)
    {
        // cout << "On Node " << src << " now\t";
        // cout << "MinSleep current value: " << minSleep << "\tSleepHours current value: " << sleepHours << "\n";
        minSleep = min(minSleep, sleepHours);
        return;
    }

    // cout << "Without Eating Fruit Case:\n";
    map<int, map<int, int>> tempPaths = paths;
    //MOVING FROM A NODE WITHOUT SLEEPING/GAINING STAMINA
    if (stamina >= node[src].minStaminatoProceed)
    {
        for (auto it : node[src].edges)
        {
            int tempStamina = stamina;
            int tempSleepHours = sleepHours;

            // cout << "Child node: " << it.first << "\n";
            // cout << "Stamina required for path: " << it.second << "\t Stamina Currently: " << tempStamina << "\n";
            if (!(tempPaths.find(src) != tempPaths.end() && tempPaths[src].find(it.first) != tempPaths[src].end()))
            {
                if (tempStamina >= it.second)
                {
                    tempPaths[src].insert({it.first, 1});
                    tempStamina -= it.second;
                    getPaths(it.first, dest, node, tempPaths, tempStamina, sleepHours);
                }
            }
            else
            {
                // cout << "Path " << src << " to " << it.first << " already traversed\n";
            }
        }
    }
    else
    {
        // cout << "Stamina less than minimum required, no chance to proceed\n";
    }

    //MOVING FROM A NODE SLEEPING AND GAINING STAMINA
    map<int, map<int, int>> tempPaths2 = paths;

    // cout << "Eating Fruit Case:\n";
    if (stamina + node[src].stamina >= node[src].minStaminatoProceed)
    {
        for (auto it : node[src].edges)
        {
            int tempStamina = stamina + node[src].stamina;
            int tempSleepHours = sleepHours + node[src].sleep;

            // cout << "Child node: " << it.first << "\n";
            // cout << "Stamina required for path: " << it.second << "\t Stamina Currently: " << tempStamina << "\n";
            if (!(tempPaths2.find(src) != tempPaths2.end() && tempPaths2[src].find(it.first) != tempPaths2[src].end()))
            {
                if (tempStamina >= it.second)
                {
                    tempPaths2[src].insert({it.first, 1});
                    tempStamina -= it.second;
                    getPaths(it.first, dest, node, tempPaths2, tempStamina, tempSleepHours);
                }
            }
            else
            {
                // cout << "Path " << src << " to " << it.first << " already traversed\n";
            }
        }
    }
    else
    {
        // cout << "Stamina less than minimum required, no chance to proceed\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    nodes node[n];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        node[x - 1].edges.emplace_back(make_pair(y - 1, z));
        node[y - 1].edges.emplace_back(make_pair(x - 1, z));
    }

    for (int i = 0; i < n; i++)
    {
        ll c, h;
        cin >> c >> h;
        node[i].stamina = c;
        node[i].sleep = h;
    }

    for (int i = 0; i < n; i++)
    {
        ll minStamina = pow(10, 10);
        for (auto it : node[i].edges)
        {
            minStamina = min(minStamina, it.second);
        }
        node[i].minStaminatoProceed = minStamina;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "For Vertex " << i << ":\n";
    //     cout << "Sleep: " << node[i].sleep << "  Stamina: " << node[i].stamina << "  Min Stamina to Proceed: " << node[i].minStaminatoProceed << "  Edges: ";
    //     for (auto it : node[i].edges)
    //     {
    //         cout << it.first << "-" << it.second << "  ";
    //     }
    //     cout << "\n";
    // }

    map<int, map<int, int>> paths;
    getPaths(a - 1, b - 1, node, paths, 0, 0);

    if (minSleep == pow(10, 14))
    {
        cout << "-1\n";
    }
    else
    {
        cout << minSleep << "\n";
    }
    return 0;
}