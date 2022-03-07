#include <iostream>

using namespace std;

int main()
{
    long t, i, j;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;

        long a[n][n];
        bool p[n][n];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                p[i][j] = false;
            }
        }
        bool is_even = true;
        long odd_count = 1, even_count = 2;
        if (n % 2 != 0)
        {
            is_even = false;
        }

        for (i = 0; i < n; i++)
        {
            a[i][i] = odd_count++;
            odd_count++;
            p[i][i] = true;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (p[i][j] == false && p[j][i] == false)
                {
                    if (is_even == false)
                    {
                        if (odd_count < n * n)
                        {
                            a[i][j] = odd_count++;
                            a[j][i] = ++odd_count;
                            odd_count = odd_count + 2;
                        }
                        else
                        {

                            a[i][j] = even_count++;
                            a[j][i] = ++even_count;
                            even_count = even_count + 2;
                        }
                    }
                    if (is_even == true)
                    {
                        if (odd_count < (n * n) - 1)
                        {
                            a[i][j] = odd_count++;
                            a[j][i] = ++odd_count;
                            odd_count = odd_count + 2;
                        }
                        else
                        {

                            a[i][j] = even_count++;
                            a[j][i] = ++even_count;
                            even_count = even_count + 2;
                        }
                    }
                    p[i][j] = true;
                    p[j][i] = true;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}