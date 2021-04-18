#include <bits/stdc++.h>
using namespace std;

struct node
{
    long long sumOfSquares;
    int sum;
};

struct updateAct
{
    int type;
    int value;
};

void buildTree(int *arr, node *tree, int start, int end, int treeNode)
{

    if (start == end)
    {
        tree[treeNode].sum = arr[start];
        tree[treeNode].sumOfSquares = (long long)arr[start] * (long long)arr[start];
        return;
    }
    int mid = (start + end) / 2;

    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    tree[treeNode].sumOfSquares = tree[2 * treeNode].sumOfSquares + tree[2 * treeNode + 1].sumOfSquares;
}

int queryTree(node *tree, int *lazy, int left, int right, int start, int end, int treeIndex)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (start >= left && end <= right)
    {
        return tree[treeIndex].sumOfSquares;
    }
    else
    {
        int mid = (start + end) / 2;
        int left, right;
        left = queryTree(tree, lazy, left, right, start, mid, treeIndex * 2);
        right = queryTree(tree, lazy, left, right, mid + 1, end, treeIndex * 2 + 1);
        return left + right;
    }
}

void updateSegmentTreeLazy(int *tree, int *lazy, int low, int high, int startR, int endR, int currPos, int inc)
{

    if (low > high)
    {
        return;
    }

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

    // No overlap
    if (startR > high || endR < low)
    {
        return;
    }

    // Complete Overlap

    if (startR <= low && high <= endR)
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
    updateSegmentTreeLazy(tree, lazy, low, mid, startR, endR, 2 * currPos, inc);
    updateSegmentTreeLazy(tree, lazy, mid + 1, high, startR, endR, 2 * currPos + 1, inc);
    tree[currPos] = min(tree[2 * currPos], tree[2 * currPos + 1]);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        node *tree = new node[3 * n]();

        buildTree(arr, tree, 0, n - 1, 1);
        int *lazy = new int[3 * n]();
        // updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 3, 1, 3);
        // updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 1, 1, 2);

        cout << "Segment Tree" << endl;
        for (int i = 1; i < 2 * n; i++)
        {
            cout << tree[i].sumOfSquares << endl;
        }

        cout << "Lazy Tree" << endl;
        for (int i = 1; i < 2 * n; i++)
        {
            cout << lazy[i] << endl;
        }
        cout << "Case " << t << ":\n";
        while (q--)
        {
            int type;
            cin >> type;
            switch (type)
            {
            case 2:
                int left, right;
                cin >> left >> right;
                cout << queryTree(tree, lazy, left - 1, right - 1, 0, n - 1, 1) << "\n";
                break;
            case 1:
                break;
            case 0:
                break;
            default:
                break;
            }
        }

        delete[] arr;
    }

    return 0;
}