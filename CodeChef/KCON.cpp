#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll kadaneSum(int a[], int n)
{
    ll currentSum = 0;
    ll maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += a[i];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    bool isAllNegative = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            isAllNegative = false;
            break;
        }
    }
    if (isAllNegative)
    {
        return *min_element(a, a + n);
    }

    return maxSum;
}

ll maxSubArraySum(int a[], int n, int k)
{
    ll kSum = kadaneSum(a, n);
    if (k == 1)
    {
        return kSum;
    }
    ll currPrefSum = 0, currSuffSum = 0;
    ll maxPrefSum = 0, maxSuffSum = 0;
    for (int i = 0; i < n; i++)
    {
        currPrefSum += a[i];
        if (currPrefSum > maxPrefSum)
        {
            maxPrefSum = currPrefSum;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        currSuffSum += a[i];
        if (currSuffSum > maxSuffSum)
        {
            maxSuffSum = currSuffSum;
        }
    }

    ll totalSum = currPrefSum;

    if (totalSum >= 0)
    {
        ll total = maxSuffSum + maxPrefSum + (totalSum * (k - 2));
        return (max(total, kSum));
    }
    else
    {
        bool isAllNegative = true;

        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 0)
            {
                isAllNegative = false;
                break;
            }
        }
        if (isAllNegative)
        {
            return *min_element(a, a + n);
        }
        return (max((maxSuffSum + maxPrefSum), kSum));
    }
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << maxSubArraySum(a, n, k) << endl;
    }
    return 0;
}