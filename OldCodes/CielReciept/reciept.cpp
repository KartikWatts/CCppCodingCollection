#include <iostream>
#include<math.h>
using namespace std;
int m;
int menu(int p)
{
    int i,var1,var2,x,y;
    for(i=0;i<12;i++)
        {
            var1=pow(2,i);
            x=p-var1;
            if(i==11)
            {
                if(x==0)
                {
                    m++;
                    break;
                }
                if(x<0)
                {
                    p=p%var1;
                    m++;
                    menu(p);
                }
            }
            var2=pow(2,i+1);
            y=p-var2;
            if(x>0 && y<0)
            {
                m++;
                p=p%var1;
                menu(p);
            }
            if(x==0 && y<0)
            {
                m++;
                break;
            }
        }
        return m;
}

int main()
{
    int T,p;
    cin>>T;
    while(T--)
    {
        cin>>p;
        cout<<menu(p);
        cout<<endl;
        m=0;
    }
    return 0;
}

