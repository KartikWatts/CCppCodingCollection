#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    // cout<<pow(2,16);
    int check = 1, temp = n;
    if (n == 1)
        return true;
    while (1)
    {
        if (temp > 1024)
        {
            while (temp > 1024)
            {
                if (temp % 1024 != 0)
                {
                    return false;
                }
                temp /= 1024;
            }
        }
        // cout<<"temp2 "<<temp<<"\t";
        // cout<<"check1 "<<check<<"\t";
        check *= 2;
        // cout<<"check2 "<<check<<"\n";
        if (check > temp)
        {
            return false;
        }
        if (check == temp)
        {
            return true;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
    cout << endl;
}