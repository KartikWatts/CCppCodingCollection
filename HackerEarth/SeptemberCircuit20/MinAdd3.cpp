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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int bit = 32;
    int n;
    cin >> n;
    int *a = new int[n];
    int **b = new int *[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = new int[bit];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i][0] = (a[i] & 1);
        for (int j = 1; j < bit - 1; j++)
        {
            a[i] = a[i] >> 1;
            b[i][j] = (a[i] & 1);
        }
    }

    ull costToGetSet[n][bit];

    for (int i = 0; i < n; i++)
    {
        if (b[i][0] == 0)
            costToGetSet[i][0] = 1;
        else
            costToGetSet[i][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        ull less = b[i][0];
        for (int j = 1; j < bit - 1; j++)
        {
            ull num = pow(2, j);
            if (b[i][j] == 0)
            {
                costToGetSet[i][j] = num - less;
            }
            else
            {
                costToGetSet[i][j] = 0;
                less += num;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < bit - 1; j++)
    //     {
    //         cout << b[i][j];
    //     }
    //     cout << "\n";
    // }
    // cout << "\nCost Matrix\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < bit - 1; j++)
    //     {
    //         cout << costToGetSet[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    ull zerosFromFirst[n][bit];
    for (int j = 0; j < bit - 1; j++)
    {
        if (b[0][j] == 0)
            zerosFromFirst[0][j] = costToGetSet[0][j];
        else
            zerosFromFirst[0][j] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < bit - 1; j++)
        {
            if (b[i][j] == 0)
                zerosFromFirst[i][j] = costToGetSet[i][j] + zerosFromFirst[i - 1][j];
            else
                zerosFromFirst[i][j] = zerosFromFirst[i - 1][j];
        }
    }

    ull zerosFromLast[n][bit];
    for (int j = 0; j < bit - 1; j++)
    {
        if (b[n - 1 - 0][j] == 0)
            zerosFromLast[0][j] = costToGetSet[n - 0 - 1][j];
        else
            zerosFromLast[0][j] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < bit - 1; j++)
        {
            if (b[n - i - 1][j] == 0)
                zerosFromLast[i][j] = costToGetSet[n - i - 1][j] + zerosFromLast[i - 1][j];
            else
                zerosFromLast[i][j] = zerosFromLast[i - 1][j];
        }
    }

    ull totalZeroes[bit];
    for (int i = 0; i < bit - 1; i++)
    {
        totalZeroes[i] = zerosFromFirst[n - 1][i];
    }

    // cout << "\nTotal Costs:\n";
    // for (int i = 0; i < bit - 1; i++)
    // {
    //     cout << totalZeroes[i] << " ";
    // }
    // cout << "\n";

    // cout << "\nCost from First Calculation\n";

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Cost in " << i + 1 << " bits from first: ";
    //     for (int j = 0; j < bit - 1; j++)
    //     {
    //         cout << zerosFromFirst[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\nCost from Last Calculation\n";

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Cost in " << i + 1 << " bits from last: ";
    //     for (int j = 0; j < bit - 1; j++)
    //     {
    //         cout << zerosFromLast[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l = l - 1;
        r = r - 1;
        ull minAdd = ull(pow(10, 18));
        // cout << "Total Zeroes in current range: ";
        for (int i = 0; i < bit - 1; i++)
        {
            ull numAdd = ull(totalZeroes[i]);
            if (l > 0)
                numAdd -= ull(zerosFromFirst[l - 1][i]);
            if (r < n - 1)
                numAdd -= ull(zerosFromLast[n - r - 2][i]);
            // cout << numAdd << " ";
            // numAdd = ull(pow(2, i)) * ull(numAdd);
            if (numAdd < minAdd)
                minAdd = numAdd;
            // cout << "MinAdd until " << i << " bit: " << minAdd << "\n";
        }
        // cout << "\n";
        cout << minAdd << "\n";
    }

    delete[] a;
    for (int i = 0; i < n; i++)
    {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}