#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int zeroes = 0, ones = 0;
        char s[1000];
        cin >> s;
        int opt = 0;
        bool required = false;
        bool change1 = false;
        bool change2 = false;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '1')
            {
                ones++;
            }
            else if (s[i] == '0')
            {
                zeroes++;
            }
        }

        if (s[0] == '0')
        {
            int i;
            for (i = 0; s[i] != '\0'; i++)
            {
                if (s[i] == '1')
                {
                    change1 = true;
                    break;
                }
            }
            if (change1 == true)
            {
                for (int j = i; s[j] != '\0'; j++)
                {
                    if (s[j] == '0')
                    {
                        change2 = true;
                        required = true;
                        break;
                    }
                }
            }
        }

        if (s[0] == '1')
        {
            int i;
            for (i = 0; s[i] != '\0'; i++)
            {
                if (s[i] == '0')
                {
                    change1 = true;
                    break;
                }
            }
            if (change1 == true)
            {
                for (int j = i; s[j] != '\0'; j++)
                {
                    if (s[j] == '1')
                    {
                        change2 = true;
                        required = true;
                        break;
                    }
                }
            }
        }

        if (required == true)
        {

            if (ones >= zeroes)
            {
                opt = zeroes;
            }
            else if (zeroes > ones)
            {
                opt = ones;
            }
        }
        cout << opt << endl;
    }
}