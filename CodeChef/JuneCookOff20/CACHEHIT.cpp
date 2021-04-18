#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, b, m;
        cin >> n >> b >> m;
        int currentBlock = -1, totalLoad = 0;
        while (m--)
        {
            int x;
            cin >> x;
            if (x / b != currentBlock)
            {
                totalLoad++;
                currentBlock = x / b;
            }
        }
        cout << totalLoad << endl;
    }
}