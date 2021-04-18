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

struct Domino
{
    int nodeIndex;
    vector<int> edges;
    int degree;
};

void dfs(stack<int> track, map<int, bool> &visited, Domino *domino, int n)
{
    while (!track.empty())
    {
        int node = track.top();
        visited.insert({node, true});
        track.pop();
        // cout << "Visited Map Updated:\t";
        // for (auto it : visited)
        // {
        //     cout << it.first + 1;
        // }
        // cout << "\n";

        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (domino[i].nodeIndex == node)
            {
                break;
            }
            index++;
        }

        for (auto it : domino[index].edges)
        {
            if (visited.find(it) == visited.end())
            {
                track.push(it);
                // cout << "Inserted node " << it + 1 << "\t";
                visited.insert({it, true});
            }
        }
    }
}

bool degreeArrange(Domino a, Domino b)
{
    if (a.degree > b.degree)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        Domino *domino = new Domino[n];
        for (int i = 0; i < n; i++)
        {
            domino[i].nodeIndex = i;
            domino[i].degree = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            domino[a - 1].edges.emplace_back(b - 1);
            domino[a - 1].degree++;
            domino[b - 1].degree--;
        }

        map<int, bool> visited;

        stack<int> track;
        int count = 0;
        sort(domino, domino + n, degreeArrange);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << "Edged from " << domino[i].nodeIndex + 1 << ":\t";
        //     for (auto it : domino[i].edges)
        //     {
        //         cout << it + 1 << ", ";
        //     }
        //     cout << "\n";
        // }
        int index = 0;
        while (visited.size() < n)
        {
            int node = domino[index].nodeIndex;
            if (visited.find(node) == visited.end())
            {
                // cout << "Analyzing for node " << node + 1 << "\n";
                track.push(node);
                dfs(track, visited, domino, n);
                count++;
            }

            index++;
        }
        cout << count << "\n";
        delete[] domino;
    }

    return 0;
}