#include <iostream>

using namespace std;
int n;
int adj[20][20];
int visit[20];
void create()
{
    int max,i,origin,dest;
    cout<<"Enter no. of nodes in Graph\t";
    cin>>n;
    max=n*n-1;
    cout<<"Enter Source and Destination adjency (0 0 to exit)";
    for(i=1;i<=max;i++)
    {
            cin>>origin>>dest;
            if(origin==0 && dest==0)
                break;
            if(origin>n || origin<=0 || dest>n || dest<=0)
            {
                cout<<"Ilegal choice";
                i--;
            }
            else
                adj[origin][dest]=1;
    }
}

void adjl()
{
    int i,j;
    cout<<"Adjacent Matrix is\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<adj[i][j]<<"\t";
        cout<<endl;
    }
}

void adjv(int v)
{
    int i;
    cout<<"Adjacent Vertices nodes are\n";
    for(i=1;i<=n;i++)
    {
        if(adj[v][i]==1)
            cout<<i<<endl;
    }
}

void bfs(int v)
{
    visit[v]=1;
    int i,front,rear;
    int que[20];
    front=rear=-1;

    front++;
    rear++;
    que[rear]=v;

    while(front<=rear)
    {
        v=que[front];
        cout<<v;
        front++;
    for(i=1;i<=n;i++)
    {
        {
            if(adj[v][i]==1 && visit[i]==0)
            {
                cout<<i;
                visit[i]=1;
                rear++;
                que[rear]=i;
            }
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
        adjl();
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
        bfs(v);
        break;
    case 5:
        exit(5);
    }
    }
    return 0;
}
