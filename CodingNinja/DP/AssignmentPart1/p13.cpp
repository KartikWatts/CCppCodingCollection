#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    int candy[n];
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> candy[i];
    }
    sort(candy, candy + n);
    int minDiff = abs(candy[n - 1] - candy[0]);
    int minIndex = 0;
    for (int i = 0; i < n - k; i++)
    {
        if (abs(candy[i + k] - candy[i]) <= minDiff)
        {
            minDiff = abs(candy[i + k] - candy[i]);
            minIndex = i;
        }
    }
    int resArray[k + 1];
    for (int i = minIndex; i < minIndex + k; i++)
    {
        resArray[i - minIndex] = candy[i];
    }
    // cout << "\nResulting Array\n";
    // for (int i = 0; i < k; i++)
    // {
    //     cout << resArray[i] << " ";
    // }
    int diffArr[k];
    for (int i = 0; i < k - 1; i++)
    {
        diffArr[i] = abs(resArray[i + 1] - resArray[i]);
    }
    // cout << "\nDifference Array\n";
    // for (int i = 0; i < k - 1; i++)
    // {
    //     cout << diffArr[i] << " ";
    // }
    int result = 0;
    // cout << "\nResult\n";
    for (int i = 1; i <= k; i++)
    {
        result += (k - i) * i * diffArr[i - 1];
    }
    cout << result << endl;
}