#include <bits/stdc++.h>
using namespace std;

void buildTree(int *tree, int *arr, int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    buildTree(tree, arr, start, mid, 2 * treenode);
    buildTree(tree, arr, mid + 1, end, 2 * treenode + 1);

    tree[treenode] = min(tree[2 * treenode], tree[2 * treenode + 1]);
}

void updateLazy(int *tree, int *lazy, int low, int high, int startR, int endR, int currPos, int inc)
{
    if (low > high)
        return;

    //Update from Lazy Tree
    if (lazy[currPos] != 0)
    {
        tree[currPos] += lazy[currPos];
        if (low != high)
        {
            lazy[2 * currPos] += lazy[currPos];
            lazy[2 * currPos + 1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }

    // NO Overlap
    if (startR > high || endR < low)
        return;

    // Complete Overlap
    if (startR <= low && endR >= high)
    {
        tree[currPos] += inc;
        if (low != high)
        {
            lazy[2 * currPos] += inc;
            lazy[2 * currPos + 1] += inc;
        }
        return;
    }

    // Partial Overlap
    int mid = (low + high) / 2;

    updateLazy(tree, lazy, low, mid, startR, endR, 2 * currPos, inc);
    updateLazy(tree, lazy, mid + 1, high, startR, endR, 2 * currPos + 1, inc);

    tree[currPos] = min(tree[2 * currPos], tree[2 * currPos + 1]);
}

int main()
{
    // cout<<"Ram";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *tree = new int[3 * n];
    int *lazy = new int[3 * n];

    buildTree(tree, arr, 0, n - 1, 1);

    int startR = 0, endR = 3, inc = 3;
    updateLazy(tree, lazy, 0, n - 1, startR, endR, 1, inc);

    startR = 0, endR = 1, inc = 2;
    updateLazy(tree, lazy, 0, n - 1, startR, endR, 1, inc);

    cout << "Segment Tree" << endl;
    for (int i = 1; i < 3 * n; i++)
    {
        cout << tree[i] << "\t";
    }

    cout << "Lazy Tree" << endl;
    for (int i = 1; i < 3 * n; i++)
    {
        cout << lazy[i] << "\t";
    }

    return 0;
}