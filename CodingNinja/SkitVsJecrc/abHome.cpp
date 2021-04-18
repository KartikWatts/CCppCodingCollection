#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long n, sqN, i, tempSq, tempCb, count = 0;
        cin >> n;
        i = 1;
        sqN = sqrt(n);
        int sqDigit = 1, sqIndex = 1;
        int cbDigit = 1, cbIndex = 1;
        while (i <= n)
        {
            tempSq = pow(sqIndex, 2);
            tempCb = pow(cbIndex, 3);
            if (tempSq < tempCb && tempSq <= n)
            {
                // cout << "Found Square for " << sqIndex << " number is " << tempSq << "\n";
                sqDigit = tempSq;
                sqIndex++;
                i = tempSq;
                count++;
            }
            else if (tempCb < tempSq && tempCb <= n)
            {
                // cout << "Found Cube for " << cbIndex << " number is " << tempCb << "\n";
                cbDigit = tempCb;
                cbIndex++;
                i = tempCb;
                count++;
            }
            else
            {
                if (tempSq <= n)
                {
                    // cout << "Found Equal for " << sqIndex << " and " << cbIndex << " number is " << tempSq << "\n";
                    sqDigit = tempSq;
                    cbDigit = tempCb;
                    sqIndex++;
                    cbIndex++;
                    i = tempSq;
                    count++;
                }
            }
            if (tempSq > n && tempCb > n)
            {
                break;
            }
            // cout << count << "\n";
        }
        cout << count << "\n";
    }
}