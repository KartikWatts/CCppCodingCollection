#include <iostream>
#include <algorithm>

using namespace std;

struct Edges
{
    int src;
    int dst;
    int wt;
};

bool sortEdges(Edges a, Edges b)
{
    if (a.wt < b.wt)
    {
        return true;
    }
    return false;
}

int get_parent(int current_vertex, int *parent)
{
    if (current_vertex == parent[current_vertex])
    {
        return current_vertex;
    }
    return get_parent(parent[current_vertex], parent);
}

int main()
{
    int v, e;
    cin >> v >> e;
    Edges input[e], output[v - 1];
    for (int i = 0; i < e; i++)
    {
        cin >> input[i].src >> input[i].dst >> input[i].wt;
        if (input[i].dst < input[i].src)
        {
            swap(input[i].dst, input[i].src);
        }
    }
    sort(input, input + e, sortEdges);

    int parent[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    int count = 0, eNo;
    while (count < v - 1)
    {
        int src = input[eNo].src;
        int dst = input[eNo].dst;
        int wt = input[eNo].wt;
        int srcParent = get_parent(src, parent);
        int dstParent = get_parent(dst, parent);
        if (srcParent != dstParent)
        {
            output[count].src = src;
            output[count].dst = dst;
            output[count].wt = wt;
            parent[dstParent] = parent[srcParent];
            count++;
        }
        eNo++;
    }
    for (int i = 0; i < v - 1; i++)
    {
        cout << output[i].src << " " << output[i].dst << " " << output[i].wt << endl;
    }
    return 0;
}