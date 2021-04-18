#include <iostream>

using namespace std;

void printString(char a[], int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << a[j];
    }
    cout << endl;
}

void bitString(char a[], int i, int n)
{
    if (i == n)
    {
        printString(a, n);
        return;
    }
    a[i] = '0';
    bitString(a, i + 1, n);
    a[i] = '1';
    bitString(a, i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    char a[n];
    bitString(a, 0, n);
}