#include <iostream>

using namespace std;

long long findMaxGCD(long long arr[], long long n)
{
    long long high = 0;
    for (long long i = 0; i < n; i++)
    {

        if (arr[i] > high)
            high = arr[i];
    }
    // high = max(high, arr[i]);

    long long count[high + 1] = {0};
    for (long long i = 0; i < n; i++)
        count[arr[i]]++;

    long long counter = 0;

    for (long long i = high; i >= 1; i--)
    {
        long long j = i;
        counter = 0;

        while (j <= high)
        {
            if (count[j] >= 2)
                return j;

            else if (count[j] == 1)
                counter++;

            j += i;

            if (counter == 2)
                return i;
        }
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
        cout << findMaxGCD(a, n) << endl;
    }
}