#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int result;
void myFun(int amount, vector<int> coins, int coin_to_be_used)
{
    int n = coins.size();
    if (amount == coin_to_be_used)
    {
        result++;
        cout << "result incremented " << result << endl;
    }
    else if (amount < coin_to_be_used)
    {
        return;
    }
    else
    {
        amount = amount - coin_to_be_used;
        for (int i = 0; i < n; i++)
        {
            cout << "inner loop for: " << coins[i] << endl;
            myFun(amount, coins, coins[i]);
        }
    }
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    for (int i = 0; i < n; i++)
    {
        // cout << coins[i];
        cout << "Started Grand Loop for Coin: " << coins[i] << endl;
        myFun(amount, coins, coins[i]);
    }
    if (result > 2)
    {
        return result / 2;
    }
    else
    {
        return result;
    }
}
int main()
{
    int amount = 3;
    // cin>>amount;
    vector<int> coins = {2};
    cout << change(amount, coins);
}
