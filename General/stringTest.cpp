#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << "Input number of strings in Vector\t";
    int n;
    cin >> n;
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        s.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << "\t";
    }
    cout << endl;
    cout << "Length of Vector: " << s.size() << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Length of String " << i + 1 << ": " << s[i].size() << endl;
    }
    cout << "**Executing operations on String 1**" << endl;
    for (int i = 0; i < s[0].size(); i++)
    {
        cout << s[0][i] << "\t";
        s[0][i] = 'R';
    }
    cout << s[0];
}