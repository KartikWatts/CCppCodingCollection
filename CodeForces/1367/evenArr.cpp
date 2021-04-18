#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int totalEven = 0, totalOdd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                totalEven++;
            else
            {
                totalOdd++;
            }
        }
        if (n % 2 == 0)
        {
            if (totalOdd != totalEven)
            {
                cout << "-1" << endl;
                continue;
            }
        }
        else
        {
            if (totalOdd + 1 != totalEven)
            {
                cout << "-1" << endl;
                continue;
            }
        }
        int checkEvenDisplaced = 0;
        for (int i = 0; i < n; i += 2)
        {
            if (a[i] % 2 != 0)
            {
                checkEvenDisplaced++;
            }
        }
        cout << checkEvenDisplaced << endl;
    }
}