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

map<string, int> months;
map<int, int> monthList;

void setMonths()
{
    months.insert({"january", 0});
    months.insert({"february", 1});
    months.insert({"march", 2});
    months.insert({"april", 3});
    months.insert({"may", 4});
    months.insert({"june", 5});
    months.insert({"july", 6});
    months.insert({"august", 7});
    months.insert({"september", 8});
    months.insert({"october", 9});
    months.insert({"november", 10});
    months.insert({"december", 11});

    monthList.insert({0, 31});
    monthList.insert({1, 29});
    monthList.insert({2, 31});
    monthList.insert({3, 30});
    monthList.insert({4, 31});
    monthList.insert({5, 30});
    monthList.insert({6, 31});
    monthList.insert({7, 31});
    monthList.insert({8, 30});
    monthList.insert({9, 31});
    monthList.insert({10, 30});
    monthList.insert({11, 31});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    setMonths();
    while (t--)
    {
        int day;
        cin >> day;
        string monthStr;
        // cin >> monthStr;
        getline(cin, monthStr);
        if (monthStr[0] == ' ')
            monthStr.erase(0, 1);
        if (monthStr[monthStr.size() - 1] == ' ')
            monthStr.substr(0, monthStr.size() - 1);
        int month = months[monthStr];
        // cout << "Current Month: " << month << "\t";
        int daysLeft = 183;
        daysLeft = daysLeft - (monthList[month] - day);
        month++;
        int dayRes;
        string monthRes;
        while (daysLeft > 0)
        {
            if (month == 12)
            {
                month = 0;
            }
            // cout << "Current Month: " << month << "\t";
            if (daysLeft > monthList[month])
            {
                daysLeft -= monthList[month];
                month++;
            }
            else
            {
                dayRes = daysLeft;
                break;
            }
        }
        for (auto it : months)
        {
            if (it.second == month)
            {
                monthRes = it.first;
                break;
            }
        }
        cout << dayRes << " " << monthRes << "\n";
    }

    return 0;
}