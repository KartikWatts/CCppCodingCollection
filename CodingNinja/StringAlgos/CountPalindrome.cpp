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

int countPalindromes(char s[])
{
    int len = strlen(s);

    int maxRes = 1;
    int totalCount = 0;
    for (int i = 0; i < len; i++)
    {
        totalCount++;
        // cout << "Working for i= " << i << "\n";
        int l = i - 1, r = i + 1, count = 1;
        while (l >= 0 && r < len && s[l] == s[r])
        {
            // cout << "Odd condition Check\t";
            count += 2;
            maxRes = max(maxRes, count);
            totalCount++;
            l--;
            r++;
        }
        l = i - 1, r = i + 2, count = 2;
        if (s[i] == s[i + 1])
        {
            totalCount++;
            while (l >= 0 && r < len && s[l] == s[r])
            {
                // cout << "Even condition Check\t";
                count += 2;
                maxRes = max(maxRes, count);
                totalCount++;
                l--;
                r++;
            }
        }
    }
    // cout << maxRes << "\n";
    return totalCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[1000];
    cin >> s;
    cout << countPalindromes(s) << "\n";

    return 0;
}