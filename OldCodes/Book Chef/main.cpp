#include <iostream>

using namespace std;

typedef struct chefbook
{
    int name;
    int pop;
    char str[30];
    int prior;
    int spec;
}book;

int main()
{
    int N,M,i,j,special,order=1;
    book c[1000];
    cin>>N>>M;
    for(i=0;i<M;i++)
        c[i].spec=0;

    for(i=0;i<N;i++)
    {
        cin>>special;
        c[special].spec=1;
    }

    for(i=0;i<M;i++)
    {
        cin>>c[i].name>>c[i].pop;
        cin>>c[i].str;
    }

    for(i=0;i<M;i++)
    {

        if(c[i].spec==1)
        {
            for(j=i+1;j<M;j++)
            {
                if(c[j].spec==1)
                {
                    if(c[i].pop > c[j].pop)
                    {
                        c[i].prior=order;
                        order++;
                    }
                    else
                    {
                        c[j].prior=order;
                        order++;
                    }
                }
            }
        }
    }

    for(i=0;i<M;i++)
    {
        if(c[i].spec!=1)
        {
            for(j=i+1;j<M;j++)
            {
                if(c[j].spec!=1)
                {
                    if(c[i].pop>c[j].pop)
                    {
                        c[i].prior=order;
                        order++;
                    }
                    else
                    {
                        c[j].prior=order;
                        order++;
                    }
                }
            }
        }
    }

    order=0;
    while(order<10000)
    {
        for(i=0;i<M;i++)
        {
            if(c[i].prior==order)
                cout<<c[i].str<<endl;
        }
        order++;
    }

    return 0;
}
