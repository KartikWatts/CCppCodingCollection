#include <iostream>
#include <math.h>

using namespace std;

int countBST(int n)
{
    int m = pow(10, 9) + 7;
    int bst[n + 1];
    bst[0] = 1;
    bst[1] = 1;
    int result = 0;
    for (int i = 2; i <= n; i++)
    {
        bst[i] = 0;
        // cout << "For i: " << i << endl;
        for (int j = 1; j <= i; j++)
        {
            // cout << "bst[i]: " << bst[i] << "\tbst[j-1]: " << bst[j - 1] << "\tbst[i-j]: " << bst[i - j] << endl;
            bst[i] = (bst[i] + bst[j - 1] * bst[i - j]) % m;
        }
    }
    return bst[n];
}

int main()
{
    int n;
    cin >> n;

    cout << countBST(n);
}