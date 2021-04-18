#include <iostream>
using namespace std;

int coin_change(int n, int *d, int numD, int **output)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (numD == 0)
    {
        return 0;
    }
    if (output[n][numD] > -1)
    {
        return output[n][numD];
    }
    int first = coin_change(n - d[0], d, numD, output);
    int second = coin_change(n, d + 1, numD - 1, output);
    output[n][numD] = first + second;
    return first + second;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{

    /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int v = value;
    int n = numDenominations;
    int **output = new int *[v + 1];
    for (int i = 0; i < v + 1; i++)
        output[i] = new int[n + 1];

    for (int i = 0; i < v + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    int res = coin_change(value, denominations, numDenominations, output);
    for (int i = 0; i < n + 1; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return res;
}

int main()
{

    int numDenominations;
    cin >> numDenominations;
    int *denominations = new int[numDenominations];
    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }
    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);
}
