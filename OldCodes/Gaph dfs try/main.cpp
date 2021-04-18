#include <iostream>

using namespace std;

int n,adj[20][20],visit[20];

void create()
{
    int max,origin,dest,i;
    cout<<"Enter no. of nodes in Graph\t";
    cin>>n;
    max=n*n-1;
    cout<<"Enter no. of Edges(Origin & Destination) {0 0 to exit}\n";
    for(i=1;i<=max;i++)
    {
        cin>>origin>>dest;
        if(origin==0 && dest==0)
            break;
        else
        adj[origin][dest]=1;
    }
}
void adjm()
{
    int i,j;
    cout<<"Matrix is\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void adjv(int v)
{
    cout<<"Edges are ";
    int i;
    for(i=1;i<=n;i++)
    {
        if(adj[v][i]==1)
            cout<<i<<"\t";
    }
}

void dfs(int v)
{
    int top=-1,pop,stack[20],i;
    top++;
    stack[top]=v;
    visit[v]=1;
    cout<<"BFS is :\n";

    while(top>=0)
    {
        pop=stack[top];
        top--;
        if(visit[pop]==0)
        {
            cout<<pop<<"\t";
            visit[pop]=1;
        }
        for(i=n;i>=1;i--)
        {
            if(adj[v][i]==0 && visit[i]==0)
            {
                cout<<pop<<"\t";
                top++;
                stack[top]=i;
            }
        }
    }
}
int main()
{
     int ch=0,i,v;
    while(ch!=5)
    {
    cout<<"Enter your choice\n";
    cout<<"1.Create\t2.Adjacency List\t3.Adjacent Vertices\t4.BSF\t5.EXIT\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
        create();
        break;
    case 2:
        adjm();
        break;
    case 3:
        cout<<"Enter node to find adjacent vertices\t";
        cin>>v;
        adjv(v);
        break;
    case 4:
        cout<<"Enter node for BFS\t";
        cin>>v;
        for(i=1;i<=n;i++)
            visit[i]=0;
        dfs(v);
        break;
    case 5:
        exit(5);
    }
    }
    return 0;
}

