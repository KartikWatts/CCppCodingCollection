#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long n = s.length();
        long long pair = 0;
        for (long long i = 0; i < n - 1;)
        {
            if ((s[i] == 'x' && s[i + 1] == 'y') || (s[i] == 'y' && s[i + 1] == 'x'))
            {
                pair++;
                i = i + 2;
            }
            else
            {
                i++;
            }
        }
        cout << pair << endl;
    }
}