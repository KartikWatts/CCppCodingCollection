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

int *GetBigInteger(string str)
{
    int x = str.size(), a = 0;

    int *arr = new int[str.size()];

    while (a != x)
    {
        arr[a] = str[a] - '0';
        a++;
    }
    return arr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int *arr = GetBigInteger(str);
        int nEvenatOdd = 0, nOddatOdd = 0;
        int nEvenatEven = 0, nOddatEven = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 2 == 0)
            {
                if (arr[i] % 2 == 0)
                {
                    nEvenatEven++;
                }
                else
                {
                    nOddatEven++;
                }
            }
            else
            {
                if (arr[i] % 2 == 0)
                {
                    nEvenatOdd++;
                }
                else
                {
                    nOddatOdd++;
                }
            }
        }

        // cout << "NOO: " << nOddatOdd << "\tNEO: " << nEvenatOdd << "\tNEE: " << nEvenatEven << "\tNOE: " << nOddatEven << "\n";

        for (int i = 0; i < n - 1; i++)
        {
            // cout << "At i= " << i << "\n";
            if (i % 2 == 0)
            {
                if (nEvenatOdd > 0)
                {
                    // cout << "cutting NEO"
                    //      << "\n";
                    nEvenatOdd--;
                }
                else
                {
                    // cout << "cutting NOO"
                    //      << "\n";
                    nOddatOdd--;
                }
            }
            else
            {
                if (nOddatEven > 0)
                {
                    // cout << "cutting NOE"
                    //      << "\n";
                    nOddatEven--;
                }
                else
                {
                    // cout << "cutting NEE"
                    //      << "\n";
                    nEvenatEven--;
                }
            }
        }
        // cout << "NOO: " << nOddatOdd << "\tNEO: " << nEvenatOdd << "\tNEE: " << nEvenatEven << "\tNOE: " << nOddatEven << "\n";
        if (nEvenatEven > 0 || nEvenatOdd > 0)
        {
            cout << "2\n";
        }
        else
        {
            cout << "1\n";
        }

        delete[] arr;
    }

    return 0;
}