#include <iostream>
using namespace std;

void girase()
{
    int n;
    cin >> n;
    int arr[n];
    int amar = 1;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 0; i < n - 1; i += 2)
    {
        arr[i] = amar;
        arr[i + 1] = 2 * amar;
        amar += 2;
    }
    if (n % 2 != 0)
    {
        arr[n - 1] = arr[n - 2] + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // your code goes here
    long long t, n;
    cin >> t;
    while (t--)
    {
        girase();
    }
    return 0;
}
