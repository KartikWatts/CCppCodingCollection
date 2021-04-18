#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stack<char> sym;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            sym.push(s[i]);
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (s[i] == ')' && sym.top() != '(')
            {
                cout << "Invalid Expression!!\n";
                return 0;
            }
            else if (s[i] == ']' && sym.top() != '[')
            {
                cout << "Invalid Expression!!\n";
                return 0;
            }
            else if (s[i] == '}' && sym.top() != '{')
            {
                cout << "Invalid Expression!!\n";
                return 0;
            }
            else
            {
                sym.pop();
            }
        }
    }
    if (sym.size() == 0)
        cout << "Valid Expression :)\n";
    else
        cout << "Invalid Expression!!\n";
    return 0;
}