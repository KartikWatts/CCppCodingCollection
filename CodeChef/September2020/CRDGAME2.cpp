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

int mod = pow(10, 9) + 7;
int range = pow(10, 5);
ull factorial[100001];
void initiate()
{
    factorial[0] = 1;
    for (int i = 1; i <= range; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}

unsigned long long power(unsigned long long x, int y)
{
    unsigned long long res = 1;

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;

        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n)
{
    return power(n, mod - 2);
}

unsigned long long nCrModPFermat(unsigned long long n, int r)
{
    if (r == 0)
        return 1;

    return (factorial[n] * modInverse(factorial[r]) % mod * modInverse(factorial[n - r]) % mod) % mod;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    initiate();
    // for (int i = 0; i <= range; i++)
    // {
    //     cout << "Factorial(" << i << "): " << factorial[i] << "\n";
    // }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *cards = new int[n];
        int maxNum = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> cards[i];
            maxNum = max(maxNum, cards[i]);
        }
        int repMax = 0;
        for (int i = 0; i < n; i++)
        {
            if (cards[i] == maxNum)
            {
                repMax++;
            }
        }

        long long res = 2;

        if (repMax % 2 != 0)
        {
            for (int i = 1; i <= n / 2; i++)
            {
                if (n % 2 != 0 || (n % 2 == 0 && i != n / 2))
                    res += nCrModPFermat(n, i) * 2;
                else
                    res += nCrModPFermat(n, i);
            }
        }
        else
        {
            for (int i = 1; i <= n / 2; i++)
            {
                int choice = n - repMax;
                int choiceSim = nCrModPFermat(repMax, repMax / 2);
                if (i >= repMax / 2)
                {
                    if (choice == 0)
                    {
                        break;
                    }
                    else
                    {
                        if (n % 2 != 0 || (n % 2 == 0 && i != n / 2))
                            res += (nCrModPFermat(n, i) - nCrModPFermat(choice, i - repMax / 2) * choiceSim) * 2;
                        else
                            res += (nCrModPFermat(n, i) - nCrModPFermat(choice, i - repMax / 2) * choiceSim);
                    }
                    // cout << "At i=" << i << " Res= " << res << endl;
                }
                else
                {
                    if (n % 2 != 0 || (n % 2 == 0 && i != n / 2))
                        res += nCrModPFermat(n, i) * 2;
                    else
                        res += nCrModPFermat(n, i);
                    // cout << "At i=" << i << " Res= " << res << endl;
                }
            }
        }

        cout << res % mod << "\n";

        delete[] cards;
    }

    return 0;
}