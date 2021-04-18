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

bool sortFun(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<pair<int, int>> bulbs;
        int maxCount = -1;
        for (int i = 0; i < n;)
        {
            if (s[i] == '0')
            {
                int count = 0;
                while (s[i] == '0')
                {
                    count++;
                    i++;
                }
                maxCount = max(maxCount, count);
                bulbs.emplace_back(make_pair(0, count));
            }
            if (s[i] == '1')
            {
                int count = 0;
                while (s[i] == '1')
                {
                    count++;
                    i++;
                }
                bulbs.emplace_back(make_pair(1, count));
            }
        }

        pair<int, int> firstB, lastB;
        firstB = {bulbs.front().first, bulbs.front().second};
        lastB = {bulbs.back().first, bulbs.back().second};

        if (k == 1)
        {
            if (firstB.first == 0 && lastB.first == 0)
            {
                k--;
                if (firstB.second >= lastB.second)
                {
                    bulbs.erase(bulbs.begin());
                }
                else
                {
                    bulbs.pop_back();
                }
            }
            else if (firstB.first == 0 && lastB.first == 1)
            {
                k--;
                bulbs.erase(bulbs.begin());
            }
            else if (lastB.first == 0 && firstB.first == 1)
            {
                k--;
                bulbs.pop_back();
            }
        }
        else if (k > 1 && bulbs.size() >= 2)
        {
            if (firstB.first == 0 && lastB.first == 0 && (firstB.second + lastB.second >= maxCount))
            {
                if (firstB.second + lastB.second >= maxCount)
                {
                    k = k - 2;
                    bulbs.erase(bulbs.begin());
                    bulbs.pop_back();
                }
            }
            else if (firstB.first == 0 && firstB.second >= maxCount)
            {
                k--;
                bulbs.erase(bulbs.begin());
            }
            else if (lastB.first == 0 && lastB.second >= maxCount)
            {
                k--;
                bulbs.pop_back();
            }
        }

        firstB = {bulbs.front().first, bulbs.front().second};
        lastB = {bulbs.back().first, bulbs.back().second};

        // for (auto it : bulbs)
        //     cout << it.first << " " << it.second << "\n";

        // cout << "First: " << firstB.first << " " << firstB.second << "\n";
        // cout << "Last: " << lastB.first << " " << lastB.second << "\n";
        sort(bulbs.begin(), bulbs.end(), sortFun);

        // cout << "Sorted: \n";
        // for (auto it : bulbs)
        //     cout << it.first << " " << it.second << "\n";

        int cleanCut = 0;
        int edgedCuts = 0;
        while (k > 0)
        {
            pair<int, int> currBulb = bulbs.at(cleanCut);
            if (edgedCuts < 2 && (currBulb.first == firstB.first && currBulb.second == firstB.second) || (currBulb.first == lastB.first && currBulb.second == lastB.second))
            {
                k--;
                if (k >= 0)
                {
                    cleanCut++;
                    edgedCuts++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                k = k - 2;
                if (k >= 0)
                {
                    cleanCut++;
                }
                else
                {
                    break;
                }
            }
        }

        int in = 0;
        int ans = 0;
        for (auto it : bulbs)
        {
            if (in < cleanCut)
            {
                in++;
                continue;
            }
            else
            {
                if (it.first == 0)
                {
                    ans += it.second;
                }
                else
                {
                    break;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}