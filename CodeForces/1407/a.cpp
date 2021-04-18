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

struct node
{
    int value;
    int evenTotal;
    int oddTotal;
    bool isIncluded;
    bool isEvenIndex;
};

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
        node a[n];
        int even1 = 0, even0 = 0, odd1 = 0, odd0 = 0;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            a[i].value = val;
            a[i].isIncluded = true;
            if (i % 2 == 0)
                a[i].isEvenIndex = true;
            else
                a[i].isEvenIndex = false;
        }
        if ((n - 1) % 2 == 0 && a[n - 1].value == 1)
        {
            a[n - 1].evenTotal = 1;
            a[n - 1].oddTotal = 0;
        }
        else if ((n - 1) % 2 != 0 && a[n - 1].value == 1)
        {
            a[n - 1].oddTotal = 1;
            a[n - 1].evenTotal = 0;
        }
        else
        {
            a[n - 1].oddTotal = 0;
            a[n - 1].evenTotal = 0;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (i % 2 == 0 && a[i].value == 1)
            {
                a[i].evenTotal = a[i + 1].evenTotal + 1;
                a[i].oddTotal = a[i + 1].oddTotal;
            }
            else if ((i % 2 != 0 && a[i].value == 1))
            {
                a[i].oddTotal = a[i + 1].oddTotal + 1;
                a[i].evenTotal = a[i + 1].evenTotal;
            }
            else
            {
                a[i].oddTotal = a[i + 1].oddTotal;
                a[i].evenTotal = a[i + 1].evenTotal;
            }
        }
        int count = 0;
        // cout << "Structure ka structure:\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << "Node: " << i << "Value: " << a[i].value << "\tEven: " << a[i].evenTotal << "\tOdd: " << a[i].oddTotal << "\n";
        // }

        int trigger = 0;
        for (int i = 0; i < n; i++)
        {
            if (trigger % 2 != 0)
            {
                if (a[i].isEvenIndex == true)
                    a[i].isEvenIndex = false;
                else
                    a[i].isEvenIndex = true;
            }
            if (a[i].evenTotal == a[i].oddTotal)
            {
                for (int j = i; j < n; j++)
                {
                    a[j].isIncluded = true;
                    count++;
                }
                break;
            }
            if (a[i].isEvenIndex == true)
            {
                a[i].isIncluded = true;
                count++;
                if (a[i].value == 1 && a[i].evenTotal > a[i].oddTotal)
                {
                    trigger++;
                    count--;
                    a[i].isIncluded = false;
                    a[i + 1].evenTotal = a[i].oddTotal;
                    a[i + 1].oddTotal = a[i].evenTotal - 1;
                }
            }
            else
            {
                count++;
                a[i].isIncluded = true;
                if (a[i].value == 1 && a[i].oddTotal > a[i].evenTotal)
                {
                    trigger++;
                    count--;
                    a[i].isIncluded = false;
                    a[i + 1].evenTotal = a[i].oddTotal - 1;
                    a[i + 1].oddTotal = a[i].evenTotal;
                }
            }
        }
        cout << count << "\n";
        for (int i = 0; i < n; i++)
        {
            if (a[i].isIncluded)
            {
                cout << a[i].value << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}