#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string b;
        cin >> b;
        int n = b.length();
        char a[n / 2 + 1];
        a[0] = b[0];
        a[n / 2] = b[n - 1];
        int index = 1;
        for (int i = 1; i <= n - 2; i += 2)
        {
            a[index++] = b[i];
        }
        for (int i = 0; i < n / 2 + 1; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
}