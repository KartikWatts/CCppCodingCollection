#include <iostream>

using namespace std;

good()
{
    m=2;
    k=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<p)
        {
            cof[k]=a[i];
            k++;
        }

    }
}
int main()
{
    cin>>n>>p;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        temp[i]=a[i];
    while(temp[i]!=0)
    {
        sum=0;
        for(j=0;j<i;j++)
        {
            sum=sum+a[j];
            if(sum<p)
            {
                max=0;
                for(k=0;k<j;k++)
                {
                    if(a[j]>max)
                    {
                        max=a[j];
                    }
                }
                maxi[z]=max;
                z++;
            }
        }
        i--;
    }
    for(i=0;i<z;i++)
    {

    }
    return 0;
}
