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

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : (((n % mod) * (factorial(n - 1) % mod)) % mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        int **board = new int *[n];
        for (int i = 0; i < n; i++)
        {
            board[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                board[i][j] = 0;
            }
        }

        int **parent = new int *[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                parent[i][j] = i * n + j;
            }
        }

        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            board[x - 1][y - 1] = 1;
        }

        // cout << "Board:\n";
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // cout << "Parent:\n";
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << parent[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        int xDim[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int yDim[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout << "Calculating for point " << i << " " << j << "\n";
                for (int k = 0; k < 8; k++)
                {
                    int moveX = i + xDim[k], moveY = j + yDim[k];
                    if (moveX >= 0 && moveX < n && moveY >= 0 && moveY < m)
                    {
                        // cout << "Valid x and y to look for: " << moveX << " " << moveY << "\t";
                        if (board[moveX][moveY] == 1 && board[i][j] == 1)
                        {
                            if (i * n + j > moveX * n + moveY)
                                parent[i][j] = parent[moveX][moveY];
                            else
                                parent[moveX][moveY] = parent[i][j];
                        }
                    }
                }
            }
        }
        // cout << "Parent:\n";
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << parent[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        map<int, int> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res[parent[i][j]]++;
            }
        }

        int result = 0;
        for (auto it : res)
        {
            if (it.second > 1)
            {
                result = (result + factorial(it.second)) % mod;
            }
        }

        cout << result << "\n";
        for (int i = 0; i < n; i++)
        {
            delete[] board[i];
        }
        delete board;
        for (int i = 0; i < n; i++)
        {
            delete[] parent[i];
        }
        delete parent;
    }

    return 0;
}